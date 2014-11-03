#include "timermanager.h"

#include "timer.h"

std::mutex TimerManager::mInsertDeletionMutex;
std::list<Timer*> TimerManager::mTimerList;
clock_t TimerManager::mLastTickTime = 0;
bool TimerManager::mbStarted = false;

void TimerManagerExecute(void)
{
    TimerManager* manager = static_cast<TimerManager*>(TimerManager::Instance());
    manager->Execute();
}

void TimerManager::Start()
{
    if (!mbStarted)
    {
        try
        {
            mThread = new std::thread(TimerManagerExecute);
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << ba.what() << " : Can't create thread to TimerManager" << std::endl;
        }
        mbStarted = true;
    }
}

void TimerManager::AddTimer(Timer *timer)
{
    static_cast<TimerManager*>(TimerManager::Instance())->Start();

    mInsertDeletionMutex.lock();
    mTimerList.push_back(timer);
    mInsertDeletionMutex.unlock();
}

void TimerManager::RemoveTimer(Timer *timer)
{
    mInsertDeletionMutex.lock();
    mTimerList.remove(timer);
    mInsertDeletionMutex.unlock();
}

void TimerManager::Execute()
{
    // Loop over list
    while(1)
    {
        // if list empty - sleep 1 second
        if (mTimerList.empty())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        else
        {
            // Start Processing timers.
            while(!mTimerList.empty())
            {
                mInsertDeletionMutex.lock();

                // time to sleep;
                clock_t minSleepTime = 0;

                for (std::list<Timer*>::iterator i = mTimerList.begin(); i != mTimerList.end(); ++i)
                {
                    Timer *timer = (*i);
                    if (nullptr == timer)
                    {
                        continue;
                    }

                    clock_t currentTime = clock();
                    int timeLeft = (int)currentTime - (int)mLastTickTime;

                    timer->MilisecondsGone(timeLeft);

                    // If time if gone need call Alarm
                    if (timer->GetMilisecondsLeft() <= 0)
                    {
                        timer->Alarm();

                        // If timer cyclic - start again.
                        if (timer->Cyclical())
                        {
                            timer->StartCycle();
                        }
                        else
                        {
                            RemoveTimer(*i);
                            continue;
                        }
                    }

                    if (timer->GetMilisecondsLeft() < minSleepTime)
                        minSleepTime = timer->GetMilisecondsLeft();
                }

                // get current time
                mLastTickTime = clock();

                std::this_thread::sleep_for(std::chrono::milliseconds(minSleepTime));

                mInsertDeletionMutex.unlock();
            }
        }
    }
}
