#ifndef TIMER_H
#define TIMER_H

#include "preinfra.h"

class Timer
{
    friend class TimerManager;
public:
    Timer();
    virtual ~Timer();

    void StartTimer(unsigned int miliseconds, bool cyclical);
    void StopTimer(void);

    virtual void Timeout(void);

    int GetMilisecondsLeft() const;
    void MilisecondsGone(int sec);

    bool Cyclical() const;
    void StartCycle();

    static std::chrono::milliseconds GetCurrentTimeMs(void);

private:
    bool mbInTimersList;

    unsigned int mMiliseconds;
    int mMilisecondsLeft;
    bool mbCyclical;
};

#endif // TIMER_H
