#include "menuscene.h"

#include "gamescene.h"

#define KEY_ENTER (13)

MenuScene::MenuScene() : SceneAbs(), mTexture(nullptr)
{
    try
    {
        mTexture = new Texture("Resources/Menus/MainMenu.bmp");
    }
    catch(std::bad_alloc &ba)
    {
        (void)ba;
        std::cerr << "MenuScene::MenuScene() Can't allocate Texture" << std::endl;
        return;
    }
}

MenuScene::~MenuScene()
{
    ;
}

void MenuScene::DrawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.4f, 1);

    glutSwapBuffers();
}

void MenuScene::KeyBoard(unsigned char &key, int &x, int &y)
{
    switch (key)
    {
    case KEY_ENTER:
        ChangeScene(new (std::nothrow) GameScene());
        break;
    default:
        SceneAbs::KeyBoard(key, x, y);
        break;
    }
}
