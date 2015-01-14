#ifndef THREAD_H
#define THREAD_H

#include "preinfra.h"

class Thread
{
    friend void ExecuteThread(Thread *ptr);
protected:
    Thread();
    virtual ~Thread();

public:
    virtual void Execute(void);

private:
    std::thread *mThread;
};

#endif // THREAD_H
