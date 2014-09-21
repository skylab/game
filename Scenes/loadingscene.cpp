#include "loadingscene.h"

#include "mainscene.h"

LoadingScene::LoadingScene()
{
}

void LoadingScene::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.4f, 1);

    //glutSwapBuffers();
}

void LoadingScene::Keyboard(int &key)
{
    switch (key)
    {
    case GLFW_KEY_ENTER:
        try
        {
            SceneManager::Instance()->ChangeScene(new MainScene());
        }
        catch(std::bad_alloc &ba)
        {
            //TODO
            (void)ba;
            return;
        }
        break;
    default:
        Scene::Keyboard(key);
        break;
    }
}