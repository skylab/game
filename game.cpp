#include "game.h"

#include <new>

Game *Game::mInstance = nullptr;

Game *Game::Instance()
{
    if (NULL == mInstance)
    {
        mInstance = new (std::nothrow) Game();
        if (NULL == mInstance)
        {
            std::cerr << "Can't allocate Game object" << std::endl;
        }
    }
    return mInstance;
}

void Game::Remove()
{
    delete mInstance;
    mInstance = nullptr;
}

void Game::Execute()
{
    if (getIsStarted())
    {
        mGraphicSystem->Draw();
    }
    else
    {
        return;
    }
}

Game::Game() : mGraphicSystem(nullptr), mPhysicSystem(nullptr), mIsStarted(false)
{
   bool started = Init();
   setIsStarted(started);
}

Game::~Game()
{
    setIsStarted(false);

    mGraphicSystem->Remove();
}

bool Game::Init()
{
    mGraphicSystem = GraphicSystem::Instance();
    //mPhysicSystem = PhysicSystem::Instance();

    return (nullptr != mGraphicSystem) ;//&& (nullptr != mPhysicSystem);
}

bool Game::getIsStarted() const
{
    return mIsStarted;
}

void Game::setIsStarted(bool value)
{
    mIsStarted = value;
}

