#ifndef THREADREGISTER_H
#define THREADREGISTER_H

#include "preinfra.h"
#include "singleton.h"

class Thread;

class ThreadRegister : public Singleton<ThreadRegister>
{
public:
    ThreadRegister();
    virtual ~ThreadRegister() override;

    void AddThread(Thread *th);
    void RemoveThread(Thread *th);
    bool ThreadValid(Thread *th);

private:
    static std::list<Thread *> mThreadRegister;
    static std::mutex mThreadListOperation;
};

#endif // THREADREGISTER_H
