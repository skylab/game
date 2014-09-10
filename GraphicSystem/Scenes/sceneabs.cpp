#include "sceneabs.h"

#include "../graphicsystem.h"

#define KEY_ESCAPE (27)

SceneAbs::SceneAbs() :
    mShaderProgram(nullptr)
{
    ;
}

SceneAbs::~SceneAbs()
{
    delete mShaderProgram;
    mShaderProgram = nullptr;
}

void SceneAbs::DrawScene()
{
    ;
}

void SceneAbs::KeyBoard(unsigned char &key, int &x, int &y)
{
    (void)x;
    (void)y;
    switch(key)
    {
    case KEY_ESCAPE:
        exit(0);
        break;
    default:
        std::cerr << "User press: " << key << std::endl;
        break;
    }
}

void SceneAbs::ChangeScene(SceneAbs *scene)
{
    if (nullptr != scene)
    {
        GraphicSystem::Instance()->ChangeScene(scene);
        GraphicSystem::Instance()->Draw();
    }
    else
    {
        std::cerr << "SceneAbs::ChangeScene new scene is nullptr" << std::endl;
    }
}

