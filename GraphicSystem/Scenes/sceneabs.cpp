#include "sceneabs.h"

#include "../graphicsystem.h"

SceneAbs::SceneAbs() :
    mShaderProgram(NULL)
{
    ;
}

SceneAbs::~SceneAbs()
{
    delete mShaderProgram;
}

void SceneAbs::DrawScene()
{
    ;
}

void SceneAbs::KeyBoard(unsigned char &key, int &x, int &y)
{
    switch(key)
    {
    case 27/*Escape*/:
        exit(0);
        break;
    default:
#ifdef _DEBUG
        std::cerr << "User press: " << key << std::endl;
#endif
        break;
    }
}

void SceneAbs::ChangeScene(SceneAbs *scene)
{
    GraphicSystem::Instance()->ChangeScene(scene);
    GraphicSystem::Instance()->Draw();
}

