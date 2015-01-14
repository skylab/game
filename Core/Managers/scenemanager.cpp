#include "scenemanager.h"

#include "../Main/scene.h"

SceneManager::SceneManager() : mCurrentScene(nullptr)
{
    ;
}

SceneManager::~SceneManager()
{
    if (nullptr != mCurrentScene)
    {
        delete mCurrentScene;
        mCurrentScene = nullptr;
    }
}

const char *SceneManager::GetName() const
{
    return __PRETTY_FUNCTION__;
}

bool SceneManager::LoadFirstScene()
{
    try
    {
        mCurrentScene = new Scene();
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << __PRETTY_FUNCTION__ << ":" << ba.what() << ": Can't allocate first scene object" << std::endl;
        mCurrentScene = nullptr;
        return false;
    }
    return true;
}

Scene *SceneManager::GetCurrentScene()
{
    return mCurrentScene;
}

void SceneManager::ChangeScene(Scene *scene)
{
    if (nullptr != mCurrentScene)
        delete mCurrentScene;

    mCurrentScene = scene;
}

void SceneManager::DrawScene()
{
    if (nullptr != mCurrentScene)
        mCurrentScene->Draw();
}
