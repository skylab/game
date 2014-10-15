#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../System/windowmanager.h"

#include "camera.h"
#include "scene.h"
#include "object.h"

class SceneObject;

class SceneManager
{
public:
    ~SceneManager();
    static SceneManager *Instance(void);
    bool InitWindowSystem(void);

    void StartScene(void);
    void ChangeScene(Scene* scene);
    Scene *GetCurrentScene(void) const;

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
    Scene *mCurrectScene;

    int mWindowWidth;
    int mWindowHeight;

    bool mbReceivedExit;
};



#endif // SCENEMANAGER_H
