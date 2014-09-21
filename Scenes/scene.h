#ifndef SCENE_H
#define SCENE_H

#include "../GraphicSystem/pregraphic.h"


#include "scenemanager.h"
#include "camera.h"

#include "SceneObject/object.h"
#include "../GraphicSystem/Shaders/shaderprogram.h"

const unsigned int KEY_ENTER(13);
const unsigned int KEY_ESCAPE(27);

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
    virtual void Keyboard(unsigned char &key, int &x, int &y);
    virtual void Mouse(int &key, int &state, int &x, int &y);

    virtual void Simulate(float speed) const;

    virtual void ChangeScene(Scene *scene);

protected:
    Scene();

protected:
    float mSimulationSpeed;

    std::list<Object*> mObjectList;
    unsigned int mObjectQuantity;

    Camera mCamera;
};

#endif // SCENE_H
