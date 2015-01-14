#include "timer.h"
#include "timermanager.h"

static std::chrono::time_point<std::chrono::high_resolution_clock> startTime(std::chrono::high_resolution_clock::now());

Timer::Timer() : mbInTimersList(false), mMiliseconds(0), mMilisecondsLeft(0), mbCyclical(false)
{
    TimerManager::Instance();
}

Timer::~Timer()
{
    if (mbInTimersList)
        TimerManager::Instance()->RemoveTimer(this);
}

void Timer::StartTimer(unsigned int miliseconds, bool cyclical)
{
    mMiliseconds = miliseconds;
    mMilisecondsLeft = mMiliseconds;
    mbCyclical = cyclical;
    TimerManager::Instance()->AddTimer(this);
}

void Timer::StopTimer()
{
    if (mbInTimersList)
        TimerManager::Instance()->RemoveTimer(this);
}

void Timer::Timeout()
{
    // Do nothing;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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

std::chrono::milliseconds Timer::GetCurrentTimeMs()
{
    std::chrono::milliseconds ms( std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime) );
    return ms;
}
