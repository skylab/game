#include "timermanager.h"

#include "timer.h"

std::mutex TimerManager::mInsertDeletionMutex;
std::list<Timer*> TimerManager::mTimerList;
std::chrono::steady_clock::time_point TimerManager::mLastWakeUpTime;
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
    // Infinity loop. Should work in all time of work programm after start
    while(1)
    {
        // If list has timers - handle it
        while(!mTimerList.empty())
        {
            mInsertDeletionMutex.lock();
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
                //std::cerr << "Gone: " << timeGone << std::endl;

                timer->MilisecondsGone(timeGone);

                if (timer->GetMilisecondsLeft() <= 0)
                {
                    timer->Alarm();

                    if (timer->Cyclical())
                        timer->StartCycle();
                    else
                        RemoveTimer(timer);
                }

                if (timer->GetMilisecondsLeft() > 0 && timer->GetMilisecondsLeft() < millToSleep)
                    millToSleep = timer->GetMilisecondsLeft();
            }
            mInsertDeletionMutex.unlock();

            mLastWakeUpTime = std::chrono::steady_clock::now();

            //std::cerr << "Sleep: " << millToSleep << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(millToSleep));
        }

        // In case of empty list - sleep 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        mLastWakeUpTime = std::chrono::steady_clock::now();
    }
}
