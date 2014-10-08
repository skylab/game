#ifndef SCENEABS_H
#define SCENEABS_H

#include "../gameobject.h"
#include "camera.h"

class SceneAbs : public GameObject
{
public:
    virtual ~SceneAbs() = 0;

    virtual void SwitchScene(SceneAbs *scene);

    virtual void SetCursorAsCamera(bool val);
    virtual const bool IsCursorAsCamera(void) const;

    virtual Camera &GetSceneCamera(void);

    /// Drawing API
    virtual void Draw(void);
    virtual void Reshape(int width, int height);
    virtual void Keyboard(int &key);
    virtual void MousePosition(double &xpos, double &ypos);

protected:
    SceneAbs();

    Camera mCamera;
    bool mbCursorIsCamera;
};

#endif // SCENEABS_H
