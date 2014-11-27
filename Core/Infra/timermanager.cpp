#include "timermanager.h"
#include "timer.h"

std::list<Timer *> TimerManager::mTimerList;
std::mutex TimerManager::mTimerListOperations;
std::chrono::steady_clock::time_point TimerManager::mLastWakeUpTime;

TimerManager::TimerManager()
{
    ;
}

TimerManager::~TimerManager()
{
    mTimerListOperations.lock();

    for (auto i : mTimerList)
    {
        Timer *t = i;
        mTimerList.remove(t);
        t->SetInTimersList(false);
        t->~Timer();
    }

    mTimerList.clear();
    mTimerListOperations.unlock();
}

void TimerManager::AddTimer(Timer *timer)
{
    mTimerListOperations.lock();
    mTimerList.push_back(timer);
    timer->SetInTimersList(true);
    mTimerListOperations.unlock();
}

void TimerManager::RemoveTimer(Timer *timer)
{
    mTimerListOperations.lock();
    mTimerList.remove(timer);
    timer->SetInTimersList(false);
    mTimerListOperations.unlock();
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
            std::chrono::steady_clock::time_point timeNow = std::chrono::steady_clock::now();

            std::chrono::duration<unsigned int, std::ratio<1,1000> > time_span = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - mLastWakeUpTime);
            timeGone = time_span.count();

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

        mLastWakeUpTime = std::chrono::steady_clock::now();

        //std::cerr << "Sleep: " << millToSleep << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(millToSleep));
    }
    else
    {
        // In case of empty list - sleep 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    mLastWakeUpTime = std::chrono::steady_clock::now();
}
