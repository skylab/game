#include "scenemanager.h"

#include "loadingscene.h"

SceneManager *SceneManager::mInstance = nullptr;

SceneManager::~SceneManager()
{
    delete mScene;
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
            //TODO
            (void)ba;
            return nullptr;
        }
    }
    return mInstance;
}

void SceneManager::ChangeScene(Scene *scene)
{
    delete mScene;
    mScene = scene;
    DrawScene();
}

Scene *SceneManager::GetCurrentScene()
{
    return mScene;
}

void SceneManager::SetWindow(GLFWwindow *window)
{
    mWindow = window;
}

const GLFWwindow *SceneManager::GetWindow() const
{
    return mWindow;
}

const int &SceneManager::GetWindowWidth() const
{
    return mWindowWidth;
}

const int &SceneManager::GetWindowHeight() const
{
    return mWindowHeight;
}

void SceneManager::DrawScene() const
{
    mScene->Draw();
}

void SceneManager::Reshape(int width, int height)
{
    mScene->Reshape(width, height);
}

void SceneManager::Keyboard(int &key)
{
    mScene->Keyboard(key);
}

void SceneManager::MousePosition(double &xpos, double &ypos)
{
    mScene->MousePosition(xpos, ypos);
}

void SceneManager::SimulateScene() const
{
    mScene->Simulate(1.0);
}

void SceneManager::SetReceivedExit(bool val)
{
    mbReceivedExit = val;
}

const bool &SceneManager::GetReceivedExit() const
{
    return mbReceivedExit;
}

SceneManager::SceneManager() : mbReceivedExit(false), mWindow(nullptr)
{
    mWindowWidth = 1024;
    mWindowHeight = 768;
    try
    {
        mScene = new LoadingScene();
    }
    catch(std::bad_alloc &ba)
    {
        //TODO
        (void)ba;
    }
}
