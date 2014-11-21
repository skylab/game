#ifndef SINGLETON_H
#define SINGLETON_H

#include <new>
#include <iostream>

#include "singletonabs.h"

// Singleton class that implement logic of work with singleton
// SingletonAbs needed to work with singleton list in singleton manager.
template<class T>
class Singleton : public SingletonAbs
{
public:
    static T* Instance()
    {
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
        return mInstance;
    }

    static void Stop(void)
    {
        mInstance->~Singleton();
    }

    virtual ~Singleton()
    {
        ;
    }


protected:
    Singleton()
    {
        ;
    }

    Singleton(const Singleton<T> &); // W/O implementation
    Singleton &operator = (const Singleton<T> &); // W/O implementation

    static T* mInstance;
};

template<class T>
T *Singleton<T>::mInstance = nullptr;

#endif // SINGLETON_H
