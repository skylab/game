#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#include "singleton.h"
#include "thread.h"

class Timer;

class TimerManager : public Singleton<TimerManager>, public Thread
{
public:
    TimerManager();
    virtual ~TimerManager();

    void AddTimer(Timer *timer);
    void RemoveTimer(Timer *timer);

    void Execute(void) override;

private:
    static std::list<Timer *> mTimerList;
    static std::mutex mTimerListOperations;
    static std::chrono::steady_clock::time_point mLastWakeUpTime;
};

#endif // TIMERMANAGER_H
