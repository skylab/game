#ifndef SINGLETON_H
#define SINGLETON_H

#include "preinfra.h"

#include "singletonabs.h"

template<class T>
class Singleton : public SingletonAbs
{
public:
    static T* Instance()
    {
        mCreationMutex.lock();
        if (nullptr == mInstance)
        {
            try
            {
                mInstance = new T();
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

protected:
    Singleton()
    {
        ;
    }

    virtual ~Singleton() override
    {
        ;
    }    

    Singleton(const Singleton&); // W/O implementation
    Singleton & operator = (const Singleton&); // W/O implementation

    static T* mInstance;
    static std::mutex mCreationMutex;
};

template<class T>
T* Singleton<T>::mInstance = nullptr;
template<class T>
std::mutex Singleton<T>::mCreationMutex;

#endif // SINGLETON_H
