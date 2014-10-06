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

    virtual const std::list<Object*> &GetObjectList(void) const;
    virtual const unsigned int &GetObjectQuantity(void) const;

    virtual Camera &GetSceneCamera(void);    
    // If true - cursor will be interpret as camera
    virtual void SetProcessCursorAsCamera(bool val);
    virtual const bool &GetProcessCursorAsCamera(void) const;

    virtual const unsigned long int GetSceneQuantityOfVertexes(void) const;

    virtual void ChangeScene(Scene *scene);

    /// Drawing API
    virtual void Draw(void) = 0;
    virtual void Reshape(int width, int height);
    virtual void Keyboard(int &key);
    virtual void MousePosition(double &xpos, double &ypos);


    /// Physic part of engine
    virtual void Simulate(float speed) const;

    virtual void SetSimulationSpeed(float &speed);
    virtual const float &GetSimulationSpeed(void) const;

protected:
    Scene();

protected:
    float mSimulationSpeed;

    std::list<Object*> mObjectList;
    unsigned int mObjectQuantity;

    Camera mCamera;
    bool mbProcessCursorAsCamera;
};

#endif // SCENE_H
