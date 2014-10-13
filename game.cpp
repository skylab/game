#include "game.h"

#include "Main/scenemanager.h"

Game *Game::mInstance = nullptr;

Game *Game::Instance()
{
    if (NULL == mInstance)
    {
        try
        {
            mInstance = new Game();
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << ba.what() << " : Can't allocate Game object" << std::endl;
        }
    }
    return mInstance;
}

void Game::Execute()
{    
    if (true == mbStarted)
    {
        mSceneManager->StartScene();
        //TODO Another thread graphic
        if (nullptr != mSceneManager)
            mSceneManager->GetWindowManager()->Draw();
        else
            std::cerr << "SceneManager is nullptr" << std::endl;

        //TODO Another thread physic
    }
    else
    {
        std::cerr << "Initialization failed. Can't execute" << std::endl;
    }
}

bool Game::Init()
{
    if (nullptr != mSceneManager)
    {
        // Init window system to draw
        mbStarted = mSceneManager->InitWindowSystem();
    }
    else
    {
        std::cerr << "Can't get SceneManager" << std::endl;
        mbStarted = false;
    }
    return mbStarted;
}

Game::Game() : mSceneManager(nullptr), mbStarted(false)
{
    mSceneManager = SceneManager::Instance();
}

Game::~Game()
{
    delete mSceneManager;
    mSceneManager = nullptr;
}
