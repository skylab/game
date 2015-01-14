#ifndef SCENE_H
#define SCENE_H

#include "../Infra/preinfra.h"
#include "camera.h"
#include "../Listeners/keyboardlistener.h"

class Object;

class Scene : public KeyboardListener
{
public:
    Scene();
    ~Scene();

    void AddObject(Object *object);
    void RemoveObject(Object *object);

    Camera *GetCamera(void);

    void Draw(void);

    virtual void CheckKeys(void) override;

private:
    std::mutex mObjectListOperation;
    Camera mCamera;
    std::list<Object *> mObjectList;
    unsigned int mLastDrawingTime;
};

#endif // SCENE_H
