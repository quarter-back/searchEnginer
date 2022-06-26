#ifndef __THREAD_HPP__
#define __THREAD_HPP__

#include "DataBag.hpp"

#include <pthread.h>
#include <functional>

class Thread{
public:
    using ThreadCallback = std::function<void(DataBag *dataPtr)>;
    Thread(ThreadCallback &&cb, DataBag *dataptr);
    ~Thread();
    void start();
    void join();

private:
    static void* threadFunc(void *);

    pthread_t _pthid;
    bool _isRunning;
    ThreadCallback _cb;
    DataBag _data;
};

#endif

