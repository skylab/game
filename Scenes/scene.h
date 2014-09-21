#ifndef SCENE_H
#define SCENE_H

#include "../GraphicSystem/pregraphic.h"

#include "SceneObject/object.h"
#include "../GraphicSystem/Shaders/shaderprogram.h"

#include "scenemanager.h"
#include "camera.h"

class Scene
{
public:
    virtual ~Scene();

    //return object ID
    virtual void AddObject(Object *object, glm::vec3 &position);

    virtual void SetSimulationSpeed(float &speed);
    virtual const float &GetSimulationSpeed(void) const;

    virtual const std::list<Object*> &GetObjectList(void) const;
    virtual const unsigned int &GetObjectQuantity(void) const;

    virtual Camera &GetSceneCamera(void);

    ///

    virtual void Draw(void) = 0;
    virtual void Reshape(int width, int height);
    virtual void Keyboard(int &key);
    virtual void MousePosition(double &xpos, double &ypos);

    virtual void Simulate(float speed) const;

    virtual void ChangeScene(Scene *scene);

protected:
    Scene();

protected:
    float mSimulationSpeed;

    std::list<Object*> mObjectList;
    unsigned int mObjectQuantity;

    Camera mCamera;

private:
    int mWindowsWidth;
    int mWindowsHeight;
};

#endif // SCENE_H
