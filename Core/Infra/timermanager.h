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

    const char *GetName(void) const override;

    void AddTimer(Timer *timer);
    void RemoveTimer(Timer *timer);

    void Execute(void) override;

private:
    std::list<Timer *> mTimerList;
    static std::mutex mTimerListOperations;
    std::chrono::high_resolution_clock::time_point mLastWakeUpTime;
};

#endif // TIMERMANAGER_H
