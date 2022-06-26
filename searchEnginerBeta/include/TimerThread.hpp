#ifndef __TIMERTHREAD_HPP__
#define __TIMERTHREAD_HPP__

#include "Timerfd.hpp"
#include "ThreadTimer.hpp"

class TimerThread
{
public:
    using TimerCallback = std::function<void()>;

    TimerThread(int initTime, int periTime, TimerCallback &&cb)
    :_timer(initTime, periTime, std::move(cb))
    ,_thread(std::bind(&Timerfd::start, &_timer))
    {}

    void start(){
        _thread.start();
    }

    void stop(){
        _timer.stop();
    }


private:
    Timerfd _timer;
    ThreadTimer _thread;
};

#endif