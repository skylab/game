#include "singletonmanager.h"

#include "singletonabs.h"

SingletonManager *SingletonManager::mInstance = nullptr;
std::mutex SingletonManager::mCreationMutex;

SingletonManager::SingletonManager()
{
    ;
}

SingletonManager::~SingletonManager()
{
    ;
}

SingletonManager *SingletonManager::Instance(void)
{
    mCreationMutex.lock();
    if (nullptr == mInstance)
    {
        try
        {
            mInstance = new SingletonManager();
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << __PRETTY_FUNCTION__ << ba.what() << std::endl;
            mInstance = nullptr;
        }
    }
    mCreationMutex.unlock();
    return mInstance;
}

void SingletonManager::AddSingleton(SingletonAbs* sng)
{
    mSingletonsList.push_back(sng);
}

void SingletonManager::RemoveSingleton(SingletonAbs* sng)
{
    mSingletonsList.remove(sng);
}

void SingletonManager::RemoveAllSingletons()
{
    while(mSingletonsList.size() != 0)
    {
        bool exist = false;
        SingletonAbs *ptr = mSingletonsList.give_back(exist);
        if (exist)
        {
            //std::cerr << "Remove: " << ptr->GetName() << std::endl;
            delete ptr;
        }
    }
}
