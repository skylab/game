#include "physicmanager.h"
#include "../ObjectLevels/PhysicLevel/physiclevel.h"
#include "../Libs/bullet/btBulletDynamicsCommon.h"

PhysicManager::PhysicManager() : mBroadphaseInterface(nullptr), mCollisionConfiguration(nullptr),
    mCollisionDispatcher(nullptr), mImpulseSolver(nullptr), mWord(nullptr)
{
    ;
}

PhysicManager::~PhysicManager()
{
    if (nullptr != mBroadphaseInterface)
        delete mBroadphaseInterface;
    if (nullptr != mCollisionConfiguration)
        delete mCollisionConfiguration;
    if (nullptr != mCollisionDispatcher)
        delete mCollisionDispatcher;
    if (nullptr != mImpulseSolver)
        delete mImpulseSolver;
    if (nullptr != mWord)
        delete mWord;
}

const char *PhysicManager::GetName() const
{
    return __PRETTY_FUNCTION__;
}

bool PhysicManager::Init()
{
    try
    {
        mBroadphaseInterface = new btDbvtBroadphase();
        mCollisionConfiguration = new btDefaultCollisionConfiguration();
        mCollisionDispatcher = new btCollisionDispatcher(mCollisionConfiguration);
        mImpulseSolver = new btSequentialImpulseConstraintSolver();
        mWord = new btDiscreteDynamicsWorld(mCollisionDispatcher, mBroadphaseInterface, mImpulseSolver, mCollisionConfiguration);
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << __PRETTY_FUNCTION__ << ":" << ba.what() << std::endl;
        return false;
    }

    mWord->setGravity(btVector3(0.0f, -9.8f, 0.0f));

    return true;
}

bool PhysicManager::AddObject(PhysicLevel *obj)
{
    ;

    return true;
}
