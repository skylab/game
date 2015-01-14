#include "threadregister.h"

std::list<Thread*> ThreadRegister::mThreadList;

ThreadRegister::ThreadRegister()
{
    ;
}

ThreadRegister::~ThreadRegister()
{
    ;
}

const char *ThreadRegister::GetName() const
{
    return __PRETTY_FUNCTION__;
}

void ThreadRegister::AddThread(Thread *thread)
{
    mThreadList.push_back(thread);
}

void ThreadRegister::RemoveThread(Thread *thread)
{
    mThreadList.remove(thread);
}

bool ThreadRegister::ThreadInList(Thread *thread)
{
    return mThreadList.end() != std::find(mThreadList.begin(), mThreadList.end(), thread);
}
