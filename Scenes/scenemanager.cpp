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

void SceneManager::DrawScene() const
{
    mScene->Draw();
}

void SceneManager::Reshape(int width, int height)
{
    mScene->Reshape(width, height);
}

void SceneManager::Keyboard(unsigned char &key, int &x, int &y)
{
    mScene->Keyboard(key, x, y);
}

void SceneManager::Mouse(int &key, int &state, int &x, int &y)
{
    mScene->Mouse(key, state, x, y);
}

void SceneManager::SimulateScene() const
{
    mScene->Simulate(1.0);
}

SceneManager::SceneManager()
{
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
