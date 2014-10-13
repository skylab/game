#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "windowmanager.h"
#include "Objects/cameraobject.h"
#include "Objects/sceneobject.h"

class SceneObject;

class SceneManager
{
public:
    ~SceneManager();
    static SceneManager *Instance(void);
    bool InitWindowSystem(void);

    void ChangeScene(SceneObject* scene);
    SceneObject *GetCurrentScene(void) const;

    WindowManager *GetWindowManager() const;

    // Drawing tools
    void DrawScene(void) const;
    void Reshape(int width, int height);
    void Keyboard(int &key, int &scancode, int &action, int &mods);
    void MousePosition(double &xpos, double &ypos);
private:
    SceneManager();

private:
    static SceneManager *mInstance;
    WindowManager *mWindowManager;
    SceneObject *mCurrectScene;

    int mWindowWidth;
    int mWindowHeight;

    bool mbReceivedExit;
};



#endif // SCENEMANAGER_H
