#ifndef SINGLETONMANAGER_H
#define SINGLETONMANAGER_H

#include "preinfra.h"

class SingletonAbs;

class SingletonManager
{
private:
    SingletonManager();
    ~SingletonManager();

public:

    static SingletonManager *Instance(void);

    void AddSingleton(SingletonAbs* sng);
    void RemoveSingleton(SingletonAbs* sng);

    void RemoveAllSingletons(void);

private:
    static SingletonManager *mInstance;
    static std::mutex mCreatinMutex;
    std::list<SingletonAbs *> mSingletonsList;
    std::mutex mListOperationMutex;
};

#endif // SINGLETONMANAGER_H
