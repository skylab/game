#include "timermanager.h"
#include "timer.h"

std::mutex TimerManager::mTimerListOperations;
//std::chrono::high_resolution_clock::time_point TimerManager::mLastWakeUpTime;

TimerManager::TimerManager()
{
    mLastWakeUpTime = std::chrono::high_resolution_clock::now();
}

TimerManager::~TimerManager()
{
    mTimerListOperations.lock();
    while(mTimerList.size() != 0)
    {
        Timer *timer = mTimerList.back();
        if (nullptr != timer)
        {
            timer->mbInTimersList = false;
            timer->~Timer();
        }
        mTimerList.remove(timer);
    }
    mTimerListOperations.unlock();
}

const char *TimerManager::GetName() const
{
    return __PRETTY_FUNCTION__;
}

void TimerManager::AddTimer(Timer *timer)
{
    while(!mTimerListOperations.try_lock())
    {
        // wait for lock mutex
    }
    mTimerList.push_back(timer);
    timer->mbInTimersList = true;
    mTimerListOperations.unlock();
}

void TimerManager::RemoveTimer(Timer *timer)
{
    if (mTimerListOperations.try_lock())
    {
        mTimerList.remove(timer);
        timer->mbInTimersList = false;
        mTimerListOperations.unlock();
    }
}

void TimerManager::Execute()
{
    if(!mTimerList.empty())
    {
        mTimerListOperations.lock();
        unsigned int millToSleep = 1;
        unsigned int timeGone = 0;
        for (std::list<Timer*>::iterator i = mTimerList.begin(); i != mTimerList.end(); ++i)
        {
            Timer *timer = *i;
            if (nullptr == timer)
            {
                mTimerList.remove(timer);
                continue;
            }
            if (mTimerList.begin() == i)
            {
                millToSleep = timer->GetMilisecondsLeft();
            }

            // Handle time difference
            std::chrono::high_resolution_clock::time_point timeNow = std::chrono::high_resolution_clock::now();
            timeGone = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - mLastWakeUpTime).count();

            //
            // timeGone contain time from last wake up.

            timer->MilisecondsGone(timeGone);

            if (timer->GetMilisecondsLeft() <= 0)
            {
                timer->Timeout();

                if (timer->Cyclical())
                    timer->StartCycle();
                else
                    RemoveTimer(timer);
            }

            // Find minimum time to sleep
            if (timer->GetMilisecondsLeft() > 0 && timer->GetMilisecondsLeft() < millToSleep)
                millToSleep = timer->GetMilisecondsLeft();
        }
        mTimerListOperations.unlock();

        mLastWakeUpTime = std::chrono::high_resolution_clock::now();

        //std::cerr << "Sleep: " << millToSleep << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(millToSleep));
    }
    else
    {
        // In case of empty list - sleep 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    //mLastWakeUpTime = std::chrono::high_resolution_clock::now();
}
