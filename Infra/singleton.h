#ifndef SINGLETON_H
#define SINGLETON_H

#include <new>
#include <iostream>
#include <typeinfo>

class Singleton
{
public:
    static Singleton* Instance();
    virtual ~Singleton();

private:
    Singleton();

    Singleton(const Singleton &); // W/O implementation
    Singleton &operator = (const Singleton &); // W/O implementation

    static Singleton* mInstance;
};

#endif // SINGLETON_H
