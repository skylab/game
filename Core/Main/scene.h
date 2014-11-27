#ifndef SCENE_H
#define SCENE_H

#include "../Infra/preinfra.h"
#include "camera.h"

class Object;

class Scene
{
public:
    Scene();
    ~Scene();

    void AddObject(Object *object);
    void RemoveObject(Object *object);

    Camera *GetCamera(void);

    void Draw(void);

private:
    std::mutex mObjectListOperation;
    Camera mCamera;
    std::list<Object *> mObjectList;
};

#endif // SCENE_H
