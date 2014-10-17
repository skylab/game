#ifndef SCENE_H
#define SCENE_H

#include "../Common/precommon.h"

class Object;
class Camera;

class Scene //: public GraphicObject
{
public:
    Scene();
    virtual ~Scene();

    void SetCursorAsCamera(bool val);
    bool IsCursorAsCamera(void) const;

    Camera *&GetCameraObject(void);

    void AddObjectToList(Object *obj, glm::vec3 position);
    const std::list<Object*> &GetObjectList(void) const;

    /// DRAW
    void Draw(void);
    void Reshape(int width, int height);
    void Keyboard(int &key, int &scancode, int &action, int &mods);
    void MousePosition(double &xpos, double &ypos);

protected:
    Camera *mCamera;
    bool mbCursorIsCamera;

    std::list<Object*> mObjectList;
};

#endif // SCENE_H
