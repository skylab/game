#ifndef THREADREGISTER_H
#define THREADREGISTER_H

#include "singleton.h"
#include "thread.h"

class ThreadRegister : public Singleton<ThreadRegister>
{
public:
    ThreadRegister();
    virtual ~ThreadRegister() override;

    virtual const char *GetName(void) const;

    void AddThread(Thread *thread);
    void RemoveThread(Thread *thread);
    bool ThreadInList(Thread *thread);

private:
    static std::list<Thread*> mThreadList;
};

#endif // THREADREGISTER_H
