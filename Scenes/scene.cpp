#include "scene.h"

#include "SceneObject/object.h"

Scene::Scene() : mSimulationSpeed(1.0f), mObjectQuantity(0), mbProcessCursorAsCamera(false)
{
    ;
}

Scene::~Scene()
{
    for(std::list<Object*>::iterator itr = mObjectList.begin(); itr != mObjectList.end(); ++itr)
    {
        delete *itr;
    }
}

void Scene::AddObject(Object *object, glm::vec3 &position)
{
    object->SetObjectPosition(position);

    object->LoadObjectToGraphicMemory();
    mObjectList.push_back(object);

    ++mObjectQuantity;
}

void Scene::SetSimulationSpeed(float &speed)
{
    mSimulationSpeed = speed;
}

const float &Scene::GetSimulationSpeed() const
{
    return mSimulationSpeed;
}

const std::list<Object *> &Scene::GetObjectList() const
{
    return mObjectList;
}

const unsigned int &Scene::GetObjectQuantity() const
{
    return mObjectQuantity;
}

Camera &Scene::GetSceneCamera()
{
    return mCamera;
}

void Scene::SetProcessCursorAsCamera(bool val)
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
    mbProcessCursorAsCamera = val;
}

const bool &Scene::GetProcessCursorAsCamera() const
{
    return mbProcessCursorAsCamera;
}

const unsigned long Scene::GetSceneQuantityOfVertexes() const
{
    unsigned long int quantity(0);

    for(const auto itr: mObjectList)
    {
        quantity += itr->GetObjectVertexQuantity();
    }

    return quantity;
}

void Scene::Draw()
{
    //TODO;
}

void Scene::Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void Scene::Keyboard(int &key)
{
    GetSceneCamera().ProcessButtonPress(key);

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

void Scene::MousePosition(double &xpos, double &ypos)
{
    if (GetProcessCursorAsCamera())
        GetSceneCamera().ProcessCursorPosition(xpos, ypos);

    // Can process this separate from camera.
}

void Scene::Simulate(float speed) const
{
    //TODO
    (void)speed;
}

void Scene::ChangeScene(Scene *scene)
{
    SceneManager::Instance()->ChangeScene(scene);
}
