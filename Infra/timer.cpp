#include "timer.h"

#include "timermanager.h"

Timer::Timer() : mMiliseconds(0), mMilisecondsLeft(0), mbCyclical(false)
{
    ;
}

Timer::~Timer()
{
    ;
}

void Timer::Start(unsigned int time, bool cyclical)
{
    mMiliseconds = time;
    mMilisecondsLeft = time;
    mbCyclical = cyclical;
    static_cast<TimerManager*>(TimerManager::Instance())->AddTimer(this);
}

void Timer::Alarm()
{
    // TODO : Warning
}

void Timer::Stop(void)
{
    static_cast<TimerManager*>(TimerManager::Instance())->RemoveTimer(this);
}

int Timer::GetMilisecondsLeft() const
{
    return mMilisecondsLeft;
}

void Timer::MilisecondsGone(int sec)
{
    mMilisecondsLeft -= sec;
}

bool Timer::Cyclical() const
{
    return mbCyclical;
}

void Timer::StartCycle()
{
    mMilisecondsLeft = mMiliseconds;
}
