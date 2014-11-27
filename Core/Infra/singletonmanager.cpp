#include "singletonmanager.h"

#include "singletonabs.h"

SingletonManager *SingletonManager::mInstance = nullptr;
std::mutex SingletonManager::mCreatinMutex;

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
    mCreatinMutex.lock();
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
    mCreatinMutex.unlock();
    return mInstance;
}

void SingletonManager::AddSingleton(SingletonAbs* sng)
{
    mListOperationMutex.lock();
    mSingletonsList.push_back(sng);
    sng->mbInSingletonList = true;
    mListOperationMutex.unlock();
}

void SingletonManager::RemoveSingleton(SingletonAbs* sng)
{
    mListOperationMutex.lock();
    mSingletonsList.remove(sng);
    sng->mbInSingletonList = false;
    mListOperationMutex.unlock();
}

void SingletonManager::RemoveAllSingletons()
{
    mListOperationMutex.lock();
    while(mSingletonsList.size() != 0)
    {
        SingletonAbs *ptr = mSingletonsList.back();
        mSingletonsList.remove(ptr);
        ptr->mbInSingletonList = false;
        delete ptr;
    }
    mListOperationMutex.unlock();
}
