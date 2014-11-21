#include "singletonabs.h"

#include "singletonmanager.h"

SingletonAbs::SingletonAbs()
{
    SingletonManager::Instance()->AddSingleton(this);
}

SingletonAbs::~SingletonAbs()
{
    SingletonManager::Instance()->RemoveSingleton(this);
}
