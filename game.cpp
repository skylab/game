#include "game.h"

#include <new>

Game *Game::mInstance = NULL;

Game *Game::Instance() throw()
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

void Game::Remove() throw()
{
    delete mInstance;
    mInstance = NULL;
}

void Game::Execute() throw()
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

Game::Game() throw() : mGraphicSystem(NULL), mIsStarted(false)
{
   bool started = Init();
   setIsStarted(started);
}

Game::~Game() throw()
{
    setIsStarted(false);

    mGraphicSystem->Remove();
}

bool Game::Init() throw()
{
    mGraphicSystem = GraphicSystem::Instance();
    return mGraphicSystem != NULL;
}

bool Game::getIsStarted() const throw()
{
    return mIsStarted;
}

void Game::setIsStarted(bool value) throw()
{
    mIsStarted = value;
}

