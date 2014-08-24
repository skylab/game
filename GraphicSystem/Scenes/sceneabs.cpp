#include "sceneabs.h"

#include "../graphicsystem.h"

SceneAbs::SceneAbs() :
    mShaderProgram(NULL), mVBO(0), mIsStarted(true)
{
    ;
}

SceneAbs::~SceneAbs()
{
    delete mShaderProgram;
}

void SceneAbs::DrawScene() const
{
    ;
}

void SceneAbs::KeyBoard(unsigned char &key, int &x, int &y)
{
    ;
}
bool SceneAbs::getIsStarted() const
{
    return mIsStarted;
}

void SceneAbs::setIsStarted(bool value)
{
    mIsStarted = value;
}

void SceneAbs::ChangeScene(SceneAbs *scene)
{
    GraphicSystem::Instance()->ChangeScene(scene);
    GraphicSystem::Instance()->Draw();
}

