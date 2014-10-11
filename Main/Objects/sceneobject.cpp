#include "sceneobject.h"

SceneObject::SceneObject()
{
    try
    {
        mCamera = new CameraObject();
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << ba.what() << " : Can't allocate camera object" << std::endl;
        return;
    }

    SetDrawObject(false);

    GameObject *obj = new GameObject();
    obj->LoadObjectFromFile("Resources/Engine.3ds");
    AddObject(obj, glm::vec3(0.0f, 0.0f, 0.0f));

}

SceneObject::~SceneObject()
{
    ;
}

void SceneObject::SetCursorAsCamera(bool val)
{
    if (val)
    {
        // Hide cursor
        glfwSetInputMode(const_cast<GLFWwindow*>(SceneManager::Instance()->GetWindow()), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        glfwSetCursorPos(const_cast<GLFWwindow*>(SceneManager::Instance()->GetWindow()), SceneManager::Instance()->GetWindowWidth()/2.0, SceneManager::Instance()->GetWindowHeight()/2.0);
    }
    else
    {
        // Show cursor
        glfwSetInputMode(const_cast<GLFWwindow*>(SceneManager::Instance()->GetWindow()), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    mbCursorIsCamera = val;
}

const bool SceneObject::IsCursorAsCamera() const
{
    return mbCursorIsCamera;
}

void SceneObject::SetCameraObject(CameraObject *camera)
{
    if (nullptr != mCamera)
    {
        std::cerr << "Camera already exist, change it" << std::endl;
        delete mCamera;
        mCamera = nullptr;
    }
    mCamera = camera;
}

void SceneObject::Draw()
{
    ;
}

void SceneObject::Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void SceneObject::Keyboard(int &key, int &scancode, int &action, int &mods)
{
    // TODO
    (void)scancode;
    (void)action;
    (void)mods;
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
