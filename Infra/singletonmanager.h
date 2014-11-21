#ifndef SINGLETONMANAGER_H
#define SINGLETONMANAGER_H

#include <list>

#include "singletonabs.h"

class SingletonManager
{
    friend class SingletonAbs;

public:
    static void Stop(void);

private:
    static SingletonManager *Instance();

    // Singleton class in constructor and destructor automatically use this functions
    void AddSingleton(SingletonAbs *sng);
    void RemoveSingleton(SingletonAbs *sng);

    SingletonManager();
    ~SingletonManager();

    static SingletonManager *mInstance;
    std::list<SingletonAbs *> mSingletonList;
};

#endif // SINGLETONMANAGER_H
