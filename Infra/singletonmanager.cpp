#include "singletonmanager.h"

#include <iostream>

SingletonManager *SingletonManager::mInstance = nullptr;

void SingletonManager::Stop()
{
    mInstance->~SingletonManager();
}

SingletonManager *SingletonManager::Instance()
{
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
    return mInstance;
}

void SingletonManager::AddSingleton(SingletonAbs *sng)
{
    if (nullptr != this)
        if (nullptr != sng)
            mSingletonList.push_back(sng);
}

void SingletonManager::RemoveSingleton(SingletonAbs *sng)
{
    if (nullptr != this)
    {
        if (nullptr != sng)
            mSingletonList.remove(sng);

        // Last Singleton remove this manager
        // Do not need care about removing this manager
        if (mSingletonList.size() == 0)
            SingletonManager::Stop();
    }
}

SingletonManager::SingletonManager()
{
}

SingletonManager::~SingletonManager()
{
    for(auto i : mSingletonList)
    {
        delete static_cast<SingletonAbs*>(i);
    }
}
