#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
    Timer();
    virtual ~Timer();

    virtual void Timeout(void);

    void SetInTimersList(bool val);
    bool GetInTimersList(void) const;

    int GetMilisecondsLeft() const;
    void MilisecondsGone(int sec);

    bool Cyclical() const;
    void StartCycle();

private:
    bool mbInTimersList;

    unsigned int mMiliseconds;
    int mMilisecondsLeft;
    bool mbCyclical;
};

#endif // TIMER_H
