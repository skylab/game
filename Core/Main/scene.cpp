#include "scene.h"

#include "../ObjectLevels/object.h"

Scene::Scene()
{
    mCamera.SetProsition(glm::vec3(0.0f, 0.0f, 3.0f));

    Object *obj = new Object();
    if (obj->LoadModel("Resources/Models/Impreza/impreza_3ds.3ds"))
        AddObject(obj);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

Scene::~Scene()
{
    mObjectListOperation.lock();
    while(mObjectList.size() != 0)
    {
        Object * object = mObjectList.back();
        mObjectList.remove(object);
        if (nullptr != object)
        {
            mObjectList.remove(object);
            delete object;
        }
    }
    mObjectListOperation.unlock();
}

void Scene::AddObject(Object *object)
{
    mObjectListOperation.lock();
    mObjectList.push_back(object);
    object->SetScene(this);
    mObjectListOperation.unlock();
}

void Scene::RemoveObject(Object *object)
{
    mObjectListOperation.lock();
    mObjectList.remove(object);
    object->SetScene(nullptr);
    mObjectListOperation.unlock();
}

Camera *Scene::GetCamera()
{
    return &mCamera;
}

void Scene::Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mObjectListOperation.lock();
    for(auto i : mObjectList)
    {
        Object *object = i;
        if (nullptr != object)
        {
            object->Draw();
        }
    }
    mObjectListOperation.unlock();
}
