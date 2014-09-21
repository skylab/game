#include "scene.h"

#include "SceneObject/object.h"

Scene::Scene() : mSimulationSpeed(1.0f), mObjectQuantity(0)
{
    mWindowsWidth = 1024;
    mWindowsHeight = 768;
    //glfwGetWindowSize(const_cast<GLFWwindow*>(SceneManager::Instance()->GetWindow()), &mWindowsWidth, &mWindowsHeight);
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
    //TODO;
    (void)key;

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
    //glm::vec3 directionVector = GetSceneCamera().GetCameraOrientation() - GetSceneCamera().GetCameraPosition();

    glfwSetCursorPos(const_cast<GLFWwindow*>(SceneManager::Instance()->GetWindow()), (double)mWindowsWidth/2, (double)mWindowsHeight/2);
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
