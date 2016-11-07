#include "threadpool.h"

#include <iostream>
#include <stdlib.h> 
#include <memory>
#include <string>
#include <functional>
#include <fstream>

#include <thread>
#include <vector>
#include <mutex>

#include <grpc++/grpc++.h>
#include "store.grpc.pb.h"
#include "vendor.grpc.pb.h"
#include "vendor.pb.h"
#include "store.pb.h"



using namespace std;

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerCompletionQueue;
using grpc::Status;

using grpc::Channel; // This channel is for the store to communicate to vendor
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;

using store::ProductQuery;
using store::ProductReply;
using store::ProductInfo;
using store::Store;

using vendor::BidQuery;
using vendor::BidReply;
using vendor::Vendor;

int numThreads;
// This class is used by the store to contact to the vendor.
// store will act as a client for Vendor

/*Global structure of vendor ip addresses that everyone can access*/
std::vector<std::string> ip_addrresses;

class VendorClient {
 public:
    friend class threadpool;
 	VendorClient(){}
  explicit VendorClient(std::shared_ptr<Channel> channel)
      : stub_(Vendor::NewStub(channel)) {}
      ~VendorClient(){}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
      // TODO: Modify this function such that it gives you... BidReply when called from
      // StoreServer's CallData class.
  BidReply getProductBid(const std::string& product_name) {
    // Data we are sending to the server.
    BidQuery request;
    // Add the initializer call here
    request.set_product_name(product_name);
    // Container for the data we expect from the server.
    BidReply reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The producer-consumer queue we use to communicate asynchronously with the
    // gRPC runtime.
    CompletionQueue cq;

    // Storage for the status of the RPC upon completion.
    Status status;

    // stub_->AsyncSayHello() performs the RPC call, returning an instance we
    // store in "rpc". Because we are using the asynchronous API, we need to
    // hold on to the "rpc" instance in order to get updates on the ongoing RPC.

	std::unique_ptr<ClientAsyncResponseReader<BidReply> > rpc(
		stub_->AsyncgetProductBid(&context, request, &cq));


    // Request that, upon completion of the RPC, "reply" be updated with the
    // server's response; "status" with the indication of whether the operation
    // was successful. Tag the request with the integer 1.

    // TODO
    rpc->Finish(&reply, &status, (void*)1);
    void* got_tag;
    bool ok = false;
    // Block until the next result is available in the completion queue "cq".
    // The return value of Next should always be checked. This return value
    // tells us whether there is any kind of event or the cq_ is shutting down.
    GPR_ASSERT(cq.Next(&got_tag, &ok));

    // Verify that the result from "cq" corresponds, by its tag, our previous
    // request.
    GPR_ASSERT(got_tag == (void*)1);
    // ... and that the request was completed successfully. Note that "ok"
    // corresponds solely to the request for updates introduced by Finish().
    GPR_ASSERT(ok);

    // Act upon the status of the actual RPC.
    if (status.ok()) {
    	std::cout<<"status ok" << std::endl;
    } 
    else {
    	std::cout << "~~~~~~~~~~~status NOT ok~~~~~~~~" << std::endl;
    }
          return reply;
  }

 private:
  // Out of the passed in Channel comes the stub, stored here, our view of the
  // server's exposed services.
  std::unique_ptr<Vendor::Stub> stub_;
  // ServerAsyncResponseWriter<BidReply> responder_;

};


class CallData {
        friend class threadpool;
        public:
            // Take in the "service" instance (in this case representing an asynchronous
            // server) and the completion queue "cq" used for asynchronous communication
            // with the gRPC runtime.
            CallData(Store::AsyncService* service, ServerCompletionQueue* cq)
            : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE) {
                // Invoke the serving logic right away.
                Proceed();
            }
            void Proceed() {
                //cout << "HI" << endl;
                if (status_ == CREATE) {
                    // Make this instance progress to the PROCESS state.
                    status_ = PROCESS;

                    // As part of the initial CREATE state, we *request* that the system
                    // start processing getProducts requests. In this request, "this" acts are
                    // the tag uniquely identifying the request (so that different CallData
                    // instances can serve different requests concurrently), in this case
                    // the memory address of this CallData instance.
                    service_->RequestgetProducts(&ctx_, &request_, &responder_, cq_, cq_,
                                                this);
                } else if (status_ == PROCESS) {
                    // Spawn a new CallData instance to serve new clients while we process
                    // the one for this CallData. The instance will deallocate itself as
                    // part of its FINISH state.
                    new CallData(service_, cq_);

                    // The actual processing.
                    /////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    // Instantiate the object for vendor-client comm.
                    int num_vendor = ip_addrresses.size();
                    std::vector<VendorClient*> VC(num_vendor);

                    int index = 0;
                    for (std::vector<std::string>::iterator itr = ip_addrresses.begin(); itr != ip_addrresses.end(); ++itr) {
                        VC[index++] = new VendorClient (grpc::CreateChannel(*itr, grpc::InsecureChannelCredentials())); 
                    }

                    std::string prd_nm = request_.product_name();
                    std::cout << "prd_nm:  " << prd_nm << std::endl;
                    for(int i=0; i < VC.size(); i++) {
                        bidr_ = VC[i]->getProductBid(prd_nm); // actual RPC

                        // There should be info field from each vendors
                        info = reply_.add_products(); // populate it for each vendor...
                        info->set_price(bidr_.price());
                        info->set_vendor_id(bidr_.vendor_id());                     
                    }
                    index = 0; // reset index
                    for (std::vector<std::string>::iterator itr = ip_addrresses.begin(); itr != ip_addrresses.end(); ++itr) {
                        delete VC[index++];
                    }                   
                    // In the end you are ready to send the reply to product reply
                    //////////////////////////////////////////////////////////////////////////////////////////////////////
                    // memory address of this instance as the uniquely identifying tag for
                    // the event.
                    status_ = FINISH;
                    responder_.Finish(reply_, Status::OK, this); // This is how we communicate to the responder..
                } else {
                    GPR_ASSERT(status_ == FINISH);
                    // Once in the FINISH state, deallocate ourselves (CallData).
                    delete this;
                }
            }
        private:
            // The means of communication with the gRPC runtime for an asynchronous
            // server.
            Store::AsyncService* service_;
            Vendor::AsyncService* vendor_service_;
            // The producer-consumer queue where for asynchronous server notifications.
            ServerCompletionQueue* cq_;
            // Context for the rpc, allowing to tweak aspects of it such as the use
            // of compression, authentication, as well as to send metadata back to the
            // client.
            ServerContext ctx_;

            // What we get from the client.
            ProductQuery request_;
            BidQuery bidq_;
            BidReply bidr_;
            // What we send back to the client.
            ProductReply reply_;
            ProductInfo *info;
            // The means to get back to the client.
            ServerAsyncResponseWriter<ProductReply> responder_;

            // Let's implement a tiny state machine with the following states.
            enum CallStatus { CREATE, PROCESS, FINISH };
            CallStatus status_;  // The current serving state.  
        };

// Now implementing asynchronous version of store server
class StoreServer final : public Store::Service {

	public:
	// Distructor
    friend class threadpool;
    threadpool *Threadpool;
	~StoreServer() {
		server_->Shutdown();
		// Always shutdown the completion queue after the server.
		cq_->Shutdown();
	} 
  
  	// There is no shutdown handling in this code.
	void Run(const std::string store_addr) {
		// std::string server_address("0.0.0.0:50050");
        Threadpool = new threadpool( numThreads );

		std::string server_address = store_addr;

		ServerBuilder builder;
		// Listen on the given address without any authentication mechanism.
		builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
		// Register "service_" as the instance through which we'll communicate with
		// clients. In this case it corresponds to an *asynchronous* service.
		builder.RegisterService(&service_);
		// Get hold of the completion queue used for the asynchronous communication
		// with the gRPC runtime.
		cq_ = builder.AddCompletionQueue(); // if we put 'auto' then it seg-fault
		// Finally assemble the server.
		server_ = builder.BuildAndStart(); // if we put 'auto' then it seg-fault
		std::cout << "Server listening on " << server_address << std::endl;

		// Proceed to the server's main loop.
        //Threadpool->add_task( [this] { HandleRpcs(); } );
        //Threadpool->add_task( &StoreServer::HandleRpcs, this );
		HandleRpcs();
	}
	private:
  	// Class encompasing the state and logic needed to serve a request.
	//
    //
    //
	// This can be run in multiple threads if needed.
	void HandleRpcs() {
		// Spawn a new CallData instance to serve new clients.
        // cout << "HI" << endl;
		CallData *ptr = new CallData(&service_, cq_.get());
		void* tag;  // uniquely identifies a request.
		bool ok = false;
		while (true) {
		  	// Block waiting to read the next event from the completion queue. The
		  	// event is uniquely identified by its tag, which in this case is the
		  	// memory address of a CallData instance.
		  	// The return value of Next should always be checked. This return value
		  	// tells us whether there is any kind of event or cq_ is shutting down.
		  	GPR_ASSERT(cq_->Next(&tag, &ok)); // control stuck into this GPS_ASSERT()
		  	GPR_ASSERT(ok);
            Threadpool->add_task( &CallData::Proceed, static_cast<CallData*>(tag) );
		  	//static_cast<CallData*>(tag)->Proceed();
		}
	}

	std::unique_ptr<ServerCompletionQueue> cq_;
  	Store::AsyncService service_;
  	std::unique_ptr<Server> server_;
};


int main(int argc, char** argv) {

	std::string filename;
	std::string store_addr;
	if (argc == 4) {
		filename = std::string(argv[1]);
		store_addr = std::string(argv[2]);
        numThreads = atoi( argv[3] );
	}
	else {
		std::cerr << "Correct usage: ./run_vendors $file_path_for_server_addrress $store_addr $num_threads" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream myfile (filename);
	if (myfile.is_open()) {
		std::string ip_addr;
		while (getline(myfile, ip_addr)) {
		    ip_addrresses.push_back(ip_addr);
		}
		myfile.close();
	}
	else {
		std::cerr << "Failed to open file " << filename << std::endl;
		return EXIT_FAILURE;
	}


	StoreServer server;
	server.Run(store_addr);

	return EXIT_SUCCESS;
}