#include "mainscene.h"

#include "../scenemanager.h"

MainScene::MainScene()
{
    GameObject * obj = new GameObject();
    glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
    obj->SetObjectPosition(pos);
    obj->LoadObjectToGraphicMemory();
    AddObject(obj);

    glm::vec3 position = glm::vec3(2.0f, 2.0f, 4.0f);
    GetSceneCamera().SetCameraPosition(position);

    glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);
    GetSceneCamera().SetCameraDirection(direction);

    float viewAngle = 90.0f;
    GetSceneCamera().SetCameraViewAngle(viewAngle);

    SetCursorAsCamera(true);

    glfwSetCursorPos(const_cast<GLFWwindow*>(SceneManager::Instance()->GetWindow()), SceneManager::Instance()->GetWindowWidth()/2.0f, SceneManager::Instance()->GetWindowHeight()/2.0f);

    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);
}

MainScene::~MainScene()
{
    ;
}

void MainScene::Keyboard(int &key)
{
    switch(key)
    {
    case GLFW_KEY_LEFT:
        break;
    case GLFW_KEY_RIGHT:
        break;
    default:
        SceneAbs::Keyboard(key);
    }
}

void MainScene::MousePosition(double &xpos, double &ypos)
{
    SceneAbs::MousePosition(xpos, ypos);
}
