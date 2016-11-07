#include <stdlib.h>
#include <thread>
#include <mutex>

#include "threadpool.h"

using namespace std;

threadpool::threadpool(int n)
    {
    thread *thread_ptr;
    numThread = n;
    int i = 0;
    int err;
    

    while(i < n)
        {       
        thread_ptr = new thread( [this] { thread_job(); } );
        thread_vec.push_back( thread_ptr );
        ++i;
        }
    }

threadpool::~threadpool()
    {

    }

void threadpool::add_task(void (CallData::*f) (void), CallData* ptr)
//void threadpool::add_task(std::function<void()> const & f)
    {
    mtx.lock();
    task_Q.push(f);
    this_Q.push(ptr);
    mtx.unlock();
    return;
    }

void threadpool::thread_job()
    {
    typedef void (CallData::*f) (void);
    CallData* current;
    while(true)
        {
        mtx.lock();
        if(task_Q.empty() != true)
            {
            f fun = task_Q.front();
            current = this_Q.front();
            task_Q.pop();
            this_Q.pop();
            mtx.unlock();
            (current->*fun)();
            }   
        else
            mtx.unlock();
        //if condition == no further job, break
        //if condition == still some jobs, AND task_Q.empty() == true, spin on a while loop, 
            //we might need mutex here, might be a deadlock
        //if condition == still some jobs, AND task_Q.empty() != true
            //, take the mutex, remove a task from the Q, execute it, delete the task, return some value to client
        }
    }