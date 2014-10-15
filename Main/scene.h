#ifndef SCENE_H
#define SCENE_H

#include "scenemanager.h"

class Console;

class Scene : public GraphicObject
{
public:
    Scene();
    virtual ~Scene();

    virtual void SetCursorAsCamera(bool val);
    virtual bool IsCursorAsCamera(void) const;

    virtual Camera *&GetCameraObject(void);

    /// DRAW
    virtual void Draw(void);
    virtual void Reshape(int width, int height);
    virtual void Keyboard(int &key, int &scancode, int &action, int &mods);
    virtual void MousePosition(double &xpos, double &ypos);

protected:
    Camera *mCamera;
    bool mbCursorIsCamera;

    //Console *mConsole;
};

#endif // SCENE_H
