#include "singletonabs.h"

#include "singletonmanager.h"

SingletonAbs::SingletonAbs()
{
    SingletonManager *manager = SingletonManager::Instance();
    if (nullptr != manager)
        manager->AddSingleton(this);
    else
        std::cerr << __PRETTY_FUNCTION__ <<  "manager is nullptr" << std::endl;
}

SingletonAbs::~SingletonAbs()
{
    // Removing from singleton manager. Already
    if (!mbInSingletonList)
        return;

    SingletonManager *manager = SingletonManager::Instance();
    if (nullptr != manager)
        manager->RemoveSingleton(this);
    else
        std::cerr << __PRETTY_FUNCTION__ <<  "manager is nullptr" << std::endl;
}
