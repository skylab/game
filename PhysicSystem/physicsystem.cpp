#include "physicsystem.h"

#include "PhysicSystem/btBulletDynamicsCommon.h"

#include <iostream>

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
    dynamicsWorld->setGravity(btVector3(0, -10, 0));

    btCollisionShape* groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), 1);

    btCollisionShape* fallShape = new btSphereShape(1);


    btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
    btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0, groundMotionState, groundShape, btVector3(0, 0, 0));
    btRigidBody* groundRigidBody = new btRigidBody(groundRigidBodyCI);
    dynamicsWorld->addRigidBody(groundRigidBody);


    btDefaultMotionState* fallMotionState =
            new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 50, 0)));
    btScalar mass = 1;
    btVector3 fallInertia(0, 0, 0);
    fallShape->calculateLocalInertia(mass, fallInertia);
    btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, fallShape, fallInertia);
    btRigidBody* fallRigidBody = new btRigidBody(fallRigidBodyCI);
    dynamicsWorld->addRigidBody(fallRigidBody);


    for (int i = 0; i < 300; i++) {
        dynamicsWorld->stepSimulation(1 / 60.f, 10);

        btTransform trans;
        fallRigidBody->getMotionState()->getWorldTransform(trans);

        std::cerr << "sphere height: " << trans.getOrigin().getY() << std::endl;
    }

    dynamicsWorld->removeRigidBody(fallRigidBody);
    delete fallRigidBody->getMotionState();
    delete fallRigidBody;

    dynamicsWorld->removeRigidBody(groundRigidBody);
    delete groundRigidBody->getMotionState();
    delete groundRigidBody;

}

PhysicSystem::PhysicSystem()
{
    Init();
}

PhysicSystem::~PhysicSystem()
{
    delete broadphase;
    delete collisionConfiguration;
    delete dispatcher;
    delete solver;
    delete dynamicsWorld;
}
