#include "scenemanager.h"

/// SceneList begin
#include "Scenes/loadingscene.h"
#include "Scenes/mainscene.h"
/// SceneList end

SceneManager *SceneManager::mInstance = nullptr;

SceneManager::~SceneManager()
{
    delete mScene;
    mScene = nullptr;
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

bool SceneManager::StartScenes()
{
    try
    {
        SwitchScene(new LoadingScene());
    }
    catch(std::bad_alloc &ba)
    {
        (void)ba;
        std::cerr << "SceneManager can't start loading scene" << std::endl;
        return false;
    }
    return true;
}

void SceneManager::SwitchScene(SceneAbs *scene)
{
    delete mScene;
    mScene = scene;
    DrawScene();
}

SceneAbs *SceneManager::GetCurrentScene()
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

void SceneManager::SetWindowWidth(size_t width)
{
    mWindowWidth = width;
}

const int &SceneManager::GetWindowWidth() const
{
    return mWindowWidth;
}

void SceneManager::SetWindowHeight(size_t height)
{
    mWindowHeight = height;
}

const int &SceneManager::GetWindowHeight() const
{
    return mWindowHeight;
}

void SceneManager::DrawScene() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

void SceneManager::SetReceivedExit(bool val)
{
    mbReceivedExit = val;
}

const bool &SceneManager::GetReceivedExit() const
{
    return mbReceivedExit;
}

SceneManager::SceneManager() : mScene(nullptr), mbReceivedExit(false), mWindow(nullptr), mWindowWidth(512), mWindowHeight(384)
{
    ;
}
