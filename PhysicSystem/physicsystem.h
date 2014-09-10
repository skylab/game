#ifndef PHYSICSYSTEM_H
#define PHYSICSYSTEM_H

class btDbvtBroadphase;
class btDefaultCollisionConfiguration;
class btCollisionDispatcher;
class btSequentialImpulseConstraintSolver;
class btDiscreteDynamicsWorld;

class PhysicSystem
{
public:
    static PhysicSystem *Instance();

private:
    PhysicSystem();
    ~PhysicSystem();
    void Init();

private:
    static PhysicSystem *mInstance;

    btDbvtBroadphase *broadphase;
    btDefaultCollisionConfiguration *collisionConfiguration;
    btCollisionDispatcher *dispatcher;
    btSequentialImpulseConstraintSolver *solver;
    btDiscreteDynamicsWorld *dynamicsWorld;
};

#endif // PHYSICSYSTEM_H
