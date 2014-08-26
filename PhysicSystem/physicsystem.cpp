#include "physicsystem.h"

#include "PhysicSystem/btBulletDynamicsCommon.h"


PhysicSystem *PhysicSystem::mInstance = NULL;

PhysicSystem *PhysicSystem::Instance()
{
    if (NULL == mInstance)
    {
        mInstance = new (std::nothrow) PhysicSystem();
        if (NULL == mInstance)
        {
            // PRINT ERROR
        }
    }
    return mInstance;
}

void PhysicSystem::Init()
{
    broadphase = new btDbvtBroadphase();
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    solver = new btSequentialImpulseConstraintSolver;
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);

    // Y is up
    //dynamicsWorld->setGravity(btVector3(0, -10, 0));
}

PhysicSystem::PhysicSystem()
{
}
