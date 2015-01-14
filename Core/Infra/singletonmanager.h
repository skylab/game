#ifndef SINGLETONMANAGER_H
#define SINGLETONMANAGER_H

#include "preinfra.h"
#include "list.h"

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
    static std::mutex mCreationMutex;

    List<SingletonAbs *> mSingletonsList;
};

#endif // SINGLETONMANAGER_H
