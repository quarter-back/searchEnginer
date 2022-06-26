#ifndef __TASKQUEUE_HPP__
#define __TASKQUEUE_HPP__

#include "MutexLock.hpp"
#include "Condition.hpp"
#include "Task.hpp"

#include <queue>

using std::queue;

class TaskQueue
{
public:
    using ElemType = Task;
    TaskQueue(int capacity);
    ~TaskQueue();

    bool isFull();
    bool isEmpty();
    void push(const ElemType &);
    ElemType pop();

    void wakeup();

private:
    int _capacity;
    queue<ElemType> _que;
    MutexLock _mutex;
    Condition _condFull;
    Condition _condEmpty;
    bool _clearFlag;
};

#endif