#include "scene.h"

Scene::Scene()
{
    try
    {
        mCamera = new Camera();
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << ba.what() << " : Can't allocate camera object" << std::endl;
        return;
    }

    mCamera->SetObjectPosition(glm::vec3(0.0f, 2.0f, 4.0f));

    Object *obj = new Object();
    obj->LoadObjectFromFile("Resources/Engine.3ds");
    AddChildObject(obj, glm::vec3(0.0f, 0.0f, 0.0f));

    ////
    Object *obj1 = new Object();
    obj1->LoadObjectFromFile("Resources/Engine.3ds");
    AddChildObject(obj1, glm::vec3(3.0f, 0.0f, 0.0f));

    Object *obj2 = new Object();
    obj2->LoadObjectFromFile("Resources/Engine.3ds");
    AddChildObject(obj2, glm::vec3(-3.0f, 0.0f, 0.0f));

    Object *obj3 = new Object();
    obj3->LoadObjectFromFile("Resources/Engine.3ds");
    AddChildObject(obj3, glm::vec3(3.0f, 2.0f, 0.0f));

    Object *obj4 = new Object();
    obj4->LoadObjectFromFile("Resources/Engine.3ds");
    AddChildObject(obj4, glm::vec3(-3.0f, 2.0f, 0.0f));
    ///

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    SetDrawObject(false);
    SetCursorAsCamera(false);
}

Scene::~Scene()
{
    ;
}

void Scene::SetCursorAsCamera(bool val)
{
    // Camera - hide cursor
    // Non camera - show cursor
    SceneManager::Instance()->GetWindowManager()->SetCursorVisible(!val);

    if (val)
    {
        // Move to center
        SceneManager::Instance()->GetWindowManager()->SetCursorPosition(
                    SceneManager::Instance()->GetWindowManager()->GetWindowWidth()/2,
                    SceneManager::Instance()->GetWindowManager()->GetWindowHeight()/2);
    }
    mbCursorIsCamera = val;
}

bool Scene::IsCursorAsCamera() const
{
    return mbCursorIsCamera;
}

Camera *&Scene::GetCameraObject()
{
    return mCamera;
}

void Scene::Draw()
{    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GraphicObject::Draw();
}

void Scene::Reshape(int width, int height)
{    
    glViewport(0, 0, width, height);
    mCamera->SetCameraViewAspectRatio(static_cast<float>(width)/static_cast<float>(height));
}

void Scene::Keyboard(int &key, int &scancode, int &action, int &mods)
{
    GetCameraObject()->ProcessButtonPress(key, scancode, action, mods);

    if (GLFW_PRESS == action || GLFW_REPEAT == action)
    {
        switch(key)
        {
        case GLFW_KEY_ESCAPE:
            SceneManager::Instance()->GetWindowManager()->Terminate();
            std::exit(0);
            break;
        case GLFW_KEY_LEFT:
            GetChildObjectList().front()->RotateHeading(0.01f);
            break;
        case GLFW_KEY_RIGHT:
            GetChildObjectList().front()->RotateHeading(-0.01f);
            break;
        case GLFW_KEY_W:
            //GetChildObjectList().front()->RotateObject(glm::vec3(10.0f, 0.0f, 0.0f));
            break;
        case GLFW_KEY_S:
            //GetChildObjectList().front()->RotateObject(glm::vec3(-10.0f, 0.0f, 0.0f));
            break;

        case GLFW_KEY_E:
            //GetChildObjectList().front()->RotateObject(glm::vec3(0.0f, 0.0f, 10.0f));
            break;
        case GLFW_KEY_Q:
            //GetChildObjectList().front()->RotateObject(glm::vec3(0.0f, 0.0f, -10.0f));
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

void Scene::MousePosition(double &xpos, double &ypos)
{
    if (IsCursorAsCamera())
    {
        mCamera->ProcessCursorPosition(xpos, ypos);
    }
}
