#include "singleton.h"

Singleton* Singleton::mInstance = nullptr;

Singleton *Singleton::Instance()
{
    if (nullptr == mInstance)
    {
        try
        {
            mInstance = new Singleton();
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << ba.what() << " Can't create signeton: " << typeid(mInstance).name() << std::endl;
        }
    }
    return mInstance;
}

Singleton::~Singleton()
{
    ;
}

Singleton::Singleton()
{
    ;
}
