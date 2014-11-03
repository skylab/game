#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#include <thread>
#include <chrono>
#include <mutex>

#include <ctime>

#include <list>

#include "../Infra/singleton.h"

class Timer;

class TimerManager : public Singleton
{
    friend void TimerManagerExecute(void);
public:
    void Start(void);

    void AddTimer(Timer *timer);
    void RemoveTimer(Timer *timer);

private:
    std::thread *mThread;
    static std::mutex mInsertDeletionMutex;
    static std::list<Timer*> mTimerList;

    static clock_t mLastTickTime;

    static bool mbStarted;

    void Execute(void);
};

#endif // TIMERMANAGER_H
