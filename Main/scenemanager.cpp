#include "scenemanager.h"

#define MY_WINDOW_WIDTH 1024
#define MY_WINDOW_HEIGHT 768

SceneManager *SceneManager::mInstance = nullptr;

SceneManager::~SceneManager()
{
    delete mWindowManager;
    mWindowManager = nullptr;
}

SceneManager *SceneManager::Instance()
{
    if (nullptr == mInstance)
    {
        try
        {
            mInstance = new SceneManager();
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << ba.what() << " : Can't create SceneManager" << std::endl;
            return nullptr;
        }
    }
    return mInstance;
}

bool SceneManager::InitWindowSystem()
{
    if (nullptr == mWindowManager)
    {
        std::cerr << "mWindowManager is nullptr" << std::endl;
        return false;
    }

    mWindowManagerStarted = mWindowManager->Createwindow(MY_WINDOW_WIDTH, MY_WINDOW_HEIGHT);
    return mWindowManagerStarted;
}

bool SceneManager::InitKeyBoardSystem()
{
    if (!mWindowManagerStarted)
    {
        if (!InitWindowSystem())
        {
            std::cerr << "InitKeyBoardSystem. mWindowManager can't init window system" << std::endl;
            return false;
        }
    }

    if (nullptr == mKeyBoardManager)
    {
        std::cerr << "InitKeyBoardSystem. mKeyBoardManager is nullptr" << std::endl;
        return false;
    }
    if (nullptr == mWindowManager)
    {
        std::cerr << "InitKeyBoardSystem. mWindowManager is nullptr" << std::endl;
        return false;
    }

    return mWindowManager->InitKeyBoard(mKeyBoardManager);
}

void SceneManager::StartScene()
{
    ChangeScene(new Scene());
}

void SceneManager::ChangeScene(Scene *scene)
{
    delete mCurrectScene;
    mCurrectScene = scene;
}

Scene *SceneManager::GetCurrentScene() const
{
    return mCurrectScene;
}

WindowManager *SceneManager::GetWindowManager() const
{
    return mWindowManager;
}

KeyBoardManager *SceneManager::GetKeyBoartManager() const
{
    return mKeyBoardManager;
}

void SceneManager::DrawScene() const
{
    if (nullptr != GetCurrentScene())
    {        
        GetCurrentScene()->Draw();
    }
    else
    {
        std::cerr << "Draw. Current scene is nullptr" << std::endl;
    }
}

void SceneManager::Reshape(int width, int height)
{
    if (nullptr != GetCurrentScene())
    {        
        GetCurrentScene()->Reshape(width, height);
    }
    else
    {
        std::cerr << "Reshape. Current scene is nullptr" << std::endl;
    }
}

/*
void SceneManager::Keyboard(int &key, int &scancode, int &action, int &mods)
{
    if (nullptr != mKeyBoardManager)
    {
        mKeyBoardManager->ProcessKey(key, scancode, action, mods);
    }
    else
    {
        std::cerr << "Keyboard. mKeyBoardManager is nullptr" << std::endl;
    }
}
*/

void SceneManager::MousePosition(double &xpos, double &ypos)
{
    if (nullptr != GetCurrentScene())
    {
        GetCurrentScene()->MousePosition(xpos, ypos);
    }
    else
    {
        std::cerr << "MousePosition. Current scene is nullptr" << std::endl;
    }
}

SceneManager::SceneManager() : mCurrectScene(nullptr)
{
    mWindowManager = WindowManager::Instance();
    mKeyBoardManager = KeyBoardManager::Instance();
}
