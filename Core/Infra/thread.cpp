#include "thread.h"

#include "threadregister.h"

void ExecuteThread(Thread *ptr)
{
    while (ThreadRegister::Instance()->ThreadValid(ptr))
    {
        ptr->Execute();
    }
}

Thread::Thread()
{
    ThreadRegister::Instance()->AddThread(this);
    try
    {
        mThread = new std::thread(ExecuteThread, this);
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << __PRETTY_FUNCTION__ << ba.what() << std::endl;
        ThreadRegister::Instance()->RemoveThread(this);
        mThread = nullptr;
    }
}

Thread::~Thread()
{
    ThreadRegister::Instance()->RemoveThread(this);
    delete mThread;
    mThread = nullptr;
}

void Thread::Execute(void)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
