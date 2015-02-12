#include "scene.h"
#include "../ObjectLevels/object.h"
#include "../Managers/windowmanager.h"
#include "../Infra/timer.h"

#include "../Managers/physicmanager.h"

Scene::Scene() : mLastDrawingTime(0)
{
    mCamera.SetProsition(glm::vec3(0.0f, 0.0f, 3.0f));

    Object *obj = new Object();

    //if (obj->LoadModel("Resources/Models/Impreza/impreza_3ds.3ds"))
        //AddObject(obj);

    if (obj->LoadModel("Resources/Models/Impreza_bmp/impreza_3ds.3ds"))
        AddObject(obj);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    PhysicManager::Instance();
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
    // Ask FPS
    //float drawDelaySec = (Timer::GetCurrentTimeMs().count() - mLastDrawingTime) / 1000.0f;
    //mLastDrawingTime = Timer::GetCurrentTimeMs().count();
    // 1 second / time delay = frames per second
    //std::cerr << 1.0f / drawDelaySec << std::endl;

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

    // To avoid overload of system add delay between frames (60 fps)
    // TODO : Remove after release
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
}

void Scene::CheckKeys(void)
{
    if (Key::Escape.Press())
    {
        std::cerr << "Received " << (const char*)Key::Escape << std::endl;
        WindowManager::Instance()->Terminate();
    }
    if (Key::F1.Press())
    {
        WindowManager::Instance()->SetWindowWindthHeight(1024, 768);
    }
    if (Key::F2.Press())
    {
        WindowManager::Instance()->SetCursorVisible(!WindowManager::Instance()->GetCorsorVisible());
    }
}
