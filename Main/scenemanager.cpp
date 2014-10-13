#include "scenemanager.h"

#include "Objects/sceneobject.h"

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
        std::cerr << "Can't create WindowManager" << std::endl;
        return false;
    }

    return mWindowManager->Createwindow(MY_WINDOW_WIDTH, MY_WINDOW_HEIGHT);
}

void SceneManager::StartScene()
{
    ChangeScene(new SceneObject());
}

void SceneManager::ChangeScene(SceneObject *scene)
{
    delete mCurrectScene;
    mCurrectScene = scene;
}

SceneObject *SceneManager::GetCurrentScene() const
{
    return mCurrectScene;
}

WindowManager *SceneManager::GetWindowManager() const
{
    return mWindowManager;
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

void SceneManager::Keyboard(int &key, int &scancode, int &action, int &mods)
{
    if (nullptr != GetCurrentScene())
    {
        GetCurrentScene()->Keyboard(key, scancode, action, mods);
    }
    else
    {
        std::cerr << "Keyboard. Current scene is nullptr" << std::endl;
    }
}

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
}
