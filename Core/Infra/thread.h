#ifndef THREAD_H
#define THREAD_H

#include "preinfra.h"

class Thread
{
protected:
    Thread();
    virtual ~Thread();

public:
    virtual void Execute(void);

private:
    std::thread *mThread;
};

#endif // THREAD_H
