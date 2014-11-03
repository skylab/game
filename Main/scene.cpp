#include "scene.h"

#include "object.h"
#include "camera.h"

#include "scenemanager.h"

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

    mCamera->SetPosition(glm::vec3(0.0f, 2.0f, 4.0f));

    Object *obj = new Object();
    obj->LoadObjectFromFile("Resources/Models/Car.3ds");
    obj->LoadTexureFromFile("Resources/Models/Diskette/brushed_metal.jpg");
    AddObjectToList(obj, glm::vec3(0.0f, 0.0f, 0.0f));

    ////
    Object *obj1 = new Object();
    obj1->LoadObjectFromFile("Resources/Models/Car.3ds");
    AddObjectToList(obj1, glm::vec3(3.0f, 0.0f, 0.0f));

    Object *obj2 = new Object();
    obj2->LoadObjectFromFile("Resources/Models/Car.3ds");
    AddObjectToList(obj2, glm::vec3(-3.0f, 0.0f, 0.0f));

    Object *obj3 = new Object();
    obj3->LoadObjectFromFile("Resources/Models/Car.3ds");
    AddObjectToList(obj3, glm::vec3(3.0f, 2.0f, 0.0f));

    Object *obj4 = new Object();
    obj4->LoadObjectFromFile("Resources/Models/Car.3ds");
    AddObjectToList(obj4, glm::vec3(-3.0f, 2.0f, 0.0f));
    ///

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    SetCursorAsCamera(false);
    SetKeyListenerEnable(true);
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

const std::list<Object *> &Scene::GetObjectList() const
{
    return mObjectList;
}

void Scene::AddObjectToList(Object *obj, glm::vec3 position)
{
    obj->SetObjectPosition(position);
    mObjectList.push_back(obj);
}

void Scene::Draw()
{    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw all elements on the scene
    for(auto itr : mObjectList)
    {
        if (nullptr != itr)
            itr->Draw();
    }
}

void Scene::Reshape(int width, int height)
{    
    glViewport(0, 0, width, height);
    mCamera->SetCameraViewAspectRatio(static_cast<float>(width)/static_cast<float>(height));
}

void Scene::NotifyKey(KeyInfo *key, ActionInfo *action, int &mods)
{
    //std::cerr << "Scene receive: " << (const char*)*key << std::endl;
    if (Key::ESCAPE == *key)
    {
        std::cerr << "Received: " << (const char*)*key << std::endl;
        SceneManager::Instance()->GetWindowManager()->Terminate();
        exit(0);
    }
    if (Key::ENTER == *key && Action::PRESS == *action)
    {
        mCamera->SetKeyListenerEnable(true);
        SetCursorAsCamera(true);
    }
    if (Key::UP == *key && Action::PRESS == *action)
    {
        Object *obj = *(mObjectList.begin());
        obj->RotatePitch(-0.01f);
    }
    if (Key::DOWN == *key && Action::PRESS == *action)
    {
        Object *obj = *(mObjectList.begin());
        obj->RotatePitch(0.01f);
    }
    if (Key::LEFT == *key && Action::PRESS == *action)
    {
        Object *obj = *(mObjectList.begin());
        obj->RotateHeading(0.01f);
    }
    if (Key::RIGHT == *key && Action::PRESS == *action)
    {
        Object *obj = *(mObjectList.begin());
        obj->RotateHeading(-0.01f);
    }
}

void Scene::MousePosition(double &xpos, double &ypos)
{
    if (IsCursorAsCamera())
    {
        mCamera->ProcessCursorPosition(xpos, ypos);
    }
}
