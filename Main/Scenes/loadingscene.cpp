#include "loadingscene.h"

#include "../scenemanager.h"
#include "mainscene.h"

LoadingScene::LoadingScene()
{
}

void LoadingScene::Keyboard(int &key)
{
    switch(key)
    {
    case GLFW_KEY_ENTER:
        try
        {
            SceneManager::Instance()->SwitchScene(new MainScene());
        }
        catch(std::bad_alloc &ba)
        {
            (void)ba;
            std::cerr << "LoadingScene can't change scene" << std::endl;
        }
        break;
    default:
        SceneAbs::Keyboard(key);
    }
}
