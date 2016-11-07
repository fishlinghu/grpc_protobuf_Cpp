#include <stdlib.h>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>

#pragma once

using namespace std;

class CallData;
//class StoreServer;

class task
    {
    public:
        void (*function)(void*);
        void *arg;
    };

class threadpool 
    {
    public:
        threadpool(int n);
        ~threadpool();
        void add_task(void (CallData::*f) (void), CallData* ptr);
        //void threadpool::add_task(std::function<void()> const & f);
        void thread_job(); 

        int numThread;
        mutex mtx;  
        //pthread_cond_t cond;
        vector<thread*> thread_vec;
        //queue<task*> task_Q;
        queue<void (CallData::*) (void)> task_Q;
        queue<CallData*> this_Q;
        //queue< std::function<void()> const & > task_Q;
    };