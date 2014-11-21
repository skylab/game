#include "game.h"

#include "GraphicSystem/pregraphic.h"
#include "Main/scenemanager.h"
#include "Infra/singletonmanager.h"

Game::Game() : mSceneManager(nullptr), mbStarted(false)
{
    if (true == Init())
        Execute();
}

Game::~Game()
{
    SingletonManager::Stop();
}

bool Game::Init()
{
    mSceneManager = SceneManager::Instance();
    if (nullptr != mSceneManager)
    {
        // Init window system to draw
        mbStarted = mSceneManager->InitWindowSystem();
        mbStarted &= mSceneManager->InitKeyBoardSystem();
    }
    else
    {
        std::cerr << __PRETTY_FUNCTION__ << " : Can't get SceneManager" << std::endl;
        mbStarted = false;
    }
    return mbStarted;
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
            std::cerr << __PRETTY_FUNCTION__ << " : SceneManager is nullptr" << std::endl;

        //TODO Another thread physic
    }
    else
    {
        std::cerr << __PRETTY_FUNCTION__ << " : Initialization failed. Can't execute" << std::endl;
    }
}
