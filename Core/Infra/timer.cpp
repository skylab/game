#include "timer.h"
#include "timermanager.h"

Timer::Timer() : mbInTimersList(false)
{
    TimerManager::Instance()->AddTimer(this);
}

Timer::~Timer()
{
    if (mbInTimersList)
        TimerManager::Instance()->RemoveTimer(this);
}

void Timer::Timeout()
{
    // Do nothing;
}

void Timer::SetInTimersList(bool val)
{
    mbInTimersList = val;
}

bool Timer::GetInTimersList() const
{
    return mbInTimersList;
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
