#ifndef __CONDITION_HPP__
#define __CONDITION_HPP__

#include <pthread.h>
#include "MutexLock.hpp"
#include "Noncopyable.hpp"

class MutexLock;
class Condition
:public Noncopyable
{
public:
    Condition(MutexLock &);
    ~Condition();
    void wait();
    void notify();
    void notifyAll();

private:
    MutexLock &_mutex;
    pthread_cond_t _cond;
};

#endif

