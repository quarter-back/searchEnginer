#ifndef __THREADPOOL_HPP__
#define __THREADPOLL_HPP__

#include "TaskQueue.hpp"
#include "Task.hpp"
#include "DataBag.hpp"

#include <memory>
#include <vector>

using std::unique_ptr;
using std::vector;

class Thread;
class Threadpool
{
public:
    friend class WorkerThread;
    Threadpool(int, int, DataBag*);
    ~Threadpool();

    void addTask(Task &&);
    void start();
    void stop();

private:
    void wokerDoTask(DataBag *dataPtr);
    Task getTask();
    

    int _threadNum;
    int _capacity;
    vector<unique_ptr<Thread>> _threads;
    TaskQueue _tq;
    bool _isExit;
    DataBag *_dataPtr;
};

#endif