#include "thread.h"

#include "threadregister.h"

void ExecuteThread(Thread *ptr)
{
    while (ThreadRegister::Instance()->ThreadInList(ptr))
    {
        ptr->Execute();
    }
}

Thread::Thread()
{
    try
    {
        ThreadRegister::Instance()->AddThread(this);
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
    mThread->join();
    delete mThread;
    mThread = nullptr;
}

void Thread::Execute(void)
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
