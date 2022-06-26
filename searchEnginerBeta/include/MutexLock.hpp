#ifndef __MUTEXLOCK_HPP__
#define __MUTEXLOCK_HPP__

#include <pthread.h>
#include "Noncopyable.hpp"

class MutexLock
:public Noncopyable
{public:
    MutexLock();
    ~MutexLock();
    void lock();
    void unlock();
    pthread_mutex_t *getMutex();
private:
    pthread_mutex_t _mutex;
};

class MutexLockGuard{
public:
    MutexLockGuard(MutexLock &);
    ~MutexLockGuard();

private:
    MutexLock &_mutex;
};

#endif

