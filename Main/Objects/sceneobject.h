#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "gameobject.h"
#include "cameraobject.h"
#include "../scenemanager.h"

class SceneObject : public Object
{
public:
    SceneObject();
    virtual ~SceneObject();

    virtual void SetCursorAsCamera(bool val);
    virtual bool IsCursorAsCamera(void) const;

    virtual CameraObject *&GetCameraObject(void);

    /// DRAW
    virtual void Draw(void);
    virtual void Reshape(int width, int height);
    virtual void Keyboard(int &key, int &scancode, int &action, int &mods);
    virtual void MousePosition(double &xpos, double &ypos);

protected:
    CameraObject *mCamera;
    bool mbCursorIsCamera;
};

#endif // SCENEOBJECT_H
