#include "sceneabs.h"

#include "../scenemanager.h"

SceneAbs::SceneAbs() : mbCursorIsCamera(false)
{
    ;
}

void SceneAbs::SwitchScene(SceneAbs *scene)
{
    SceneManager::Instance()->SwitchScene(scene);
}

void SceneAbs::SetCursorAsCamera(bool val)
{
    if (val)
    {
        glfwSetInputMode(const_cast<GLFWwindow*>(SceneManager::Instance()->GetWindow()), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        glfwSetCursorPos(const_cast<GLFWwindow*>(SceneManager::Instance()->GetWindow()), SceneManager::Instance()->GetWindowWidth()/2.0, SceneManager::Instance()->GetWindowHeight()/2.0);
    }
    else
    {
       glfwSetInputMode(const_cast<GLFWwindow*>(SceneManager::Instance()->GetWindow()), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    mbCursorIsCamera = val;
}

const bool SceneAbs::IsCursorAsCamera() const
{
    return mbCursorIsCamera;
}

Camera &SceneAbs::GetSceneCamera()
{
    return mSceneCamera;
}

void SceneAbs::Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void SceneAbs::Keyboard(int &key)
{
    switch(key)
    {
    case GLFW_KEY_ESCAPE:
        SceneManager::Instance()->SetReceivedExit(true);
        break;
    default:
        std::cerr << "User press: " << key << std::endl;
        break;
    }
}

void SceneAbs::MousePosition(double &xpos, double &ypos)
{
    if (IsCursorAsCamera())
        mCamera.ProcessCursorPosition(xpos, ypos);
}

void SceneAbs::Draw()
{    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Background color
    GraphicObject::Draw();
}

SceneAbs::~SceneAbs()
{
    ClearObjectList();
}
