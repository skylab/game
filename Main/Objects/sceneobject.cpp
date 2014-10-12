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

    mCamera->SetObjectPosition(glm::vec3(2.0f, 2.0f, -2.0f));

    GameObject *obj = new GameObject();
    obj->LoadObjectFromFile("Resources/Engine.3ds");
    AddChildObject(obj, glm::vec3(0.0f, 0.0f, 0.0f));

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    SetDrawObject(false);
    SetCursorAsCamera(false);
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

bool SceneObject::IsCursorAsCamera() const
{
    return mbCursorIsCamera;
}

CameraObject *&SceneObject::GetCameraObject()
{
    return mCamera;
}

void SceneObject::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GraphicObject::Draw();
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

    if (GLFW_PRESS == action || GLFW_REPEAT == action)
    {
        switch(key)
        {
        case GLFW_KEY_ESCAPE:
            SceneManager::Instance()->SetReceivedExit(true);
            break;
        case GLFW_KEY_LEFT:
            GetChildObjectList().front()->RotateObject(glm::vec3(0.0f, 0.01f, 0.0f));
            break;
        case GLFW_KEY_RIGHT:
            GetChildObjectList().front()->RotateObject(glm::vec3(0.0f, -0.01f, 0.0f));
            break;
        case GLFW_KEY_UP:
            GetChildObjectList().front()->RotateObject(glm::vec3(0.01f, 0.0f, 0.0f));
            break;
        case GLFW_KEY_DOWN:
            GetChildObjectList().front()->RotateObject(glm::vec3(-0.01f, 0.0f, 0.0f));
            break;
        case GLFW_KEY_ENTER:
            SetCursorAsCamera(!IsCursorAsCamera());
            break;
        default:
            //std::cerr << "User press: " << key << std::endl;
            break;
        }
    }
}

void SceneObject::MousePosition(double &xpos, double &ypos)
{
    if (IsCursorAsCamera())
    {
        mCamera->ProcessCursorPosition(xpos, ypos);
    }
}
