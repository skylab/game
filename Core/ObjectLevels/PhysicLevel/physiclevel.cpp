#include "physiclevel.h"

//#include "../../Libs/bullet/btBulletDynamicsCommon.h"

#include "../../Managers/physicmanager.h"

PhysicLevel::PhysicLevel()
{
    PhysicManager::Instance()->AddObject(this);
}

PhysicLevel::~PhysicLevel()
{
    ;
}
