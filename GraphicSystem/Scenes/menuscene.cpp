#include "menuscene.h"

#include "gamescene.h"

MenuScene::MenuScene() : SceneAbs()
{
    ;
}

MenuScene::~MenuScene()
{
    ;
}

void MenuScene::DrawScene() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.4f, 1);

    glutSwapBuffers();
}

void MenuScene::KeyBoard(unsigned char &key, int &x, int &y)
{
    switch (key)
    {
    case 13:
        ChangeScene(new (std::nothrow) GameScene());
        break;
    default:
        SceneAbs::KeyBoard(key, x, y);
        break;
    }
}
