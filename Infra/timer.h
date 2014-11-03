#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
    Timer();
    virtual ~Timer();

    void Start(unsigned int time, bool cyclical);
    virtual void Alarm(void) = 0;
    void Stop(void);

    int GetMilisecondsLeft(void) const;
    void MilisecondsGone(int sec);

    bool Cyclical(void) const;
    void StartCycle();

private:
    unsigned int mMiliseconds;
    int mMilisecondsLeft;
    bool mbCyclical;
};

#endif // TIMER_H
