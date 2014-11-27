#include "threadregister.h"

std::list<Thread *> ThreadRegister::mThreadRegister;
std::mutex ThreadRegister::mThreadListOperation;

ThreadRegister::ThreadRegister()
{
    ;
}

ThreadRegister::~ThreadRegister()
{
    ;
}

void ThreadRegister::AddThread(Thread *th)
{
    mThreadListOperation.lock();
    mThreadRegister.push_back(th);
    mThreadListOperation.unlock();
}

void ThreadRegister::RemoveThread(Thread *th)
{
    mThreadListOperation.lock();
    mThreadRegister.remove(th);
    mThreadListOperation.unlock();
}

bool ThreadRegister::ThreadValid(Thread *th)
{
    mThreadListOperation.lock();

    if (mThreadRegister.empty())
    {
        mThreadListOperation.unlock();
        return false;
    }

    bool found = false;

    for(auto i : mThreadRegister)
    {
        if (th == i)
            found = true;
    }

    mThreadListOperation.unlock();
    return found;
}
