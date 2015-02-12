#ifndef PHYSICMANAGER_H
#define PHYSICMANAGER_H

#include "../Infra/singleton.h"

class PhysicLevel;

class btBroadphaseInterface;
class btDefaultCollisionConfiguration;
class btCollisionDispatcher;
class btSequentialImpulseConstraintSolver;
class btDiscreteDynamicsWorld;

class PhysicManager : public Singleton<PhysicManager>
{
public:
    PhysicManager();
    virtual ~PhysicManager() override;

    virtual const char *GetName() const override;

    bool Init(void);

    bool AddObject(PhysicLevel *obj);

private:
    btBroadphaseInterface *mBroadphaseInterface;
    btDefaultCollisionConfiguration *mCollisionConfiguration;
    btCollisionDispatcher *mCollisionDispatcher;
    btSequentialImpulseConstraintSolver *mImpulseSolver;
    btDiscreteDynamicsWorld *mWord;
};

#endif // PHYSICMANAGER_H
