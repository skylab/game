#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Infra/singleton.h"

#include "../System/windowmanager.h"
#include "../System/keyboardmanager.h"

#include "camera.h"
#include "scene.h"
#include "object.h"

class Scene;

class SceneManager : public Singleton<SceneManager>
{
public:
    SceneManager();
    ~SceneManager();
    bool InitWindowSystem(void);
    bool InitKeyBoardSystem(void);

    void StartScene(void);
    void ChangeScene(Scene* scene);
    Scene *GetCurrentScene(void) const;

    WindowManager *GetWindowManager() const;
    KeyBoardManager *GetKeyBoartManager() const;

    // Drawing tools
    void DrawScene(void) const;
    void Reshape(int width, int height);
    void Keyboard(int &key, int &scancode, int &action, int &mods);
    void MousePosition(double &xpos, double &ypos);

private:
    WindowManager *mWindowManager;
    bool mWindowManagerStarted;
    KeyBoardManager *mKeyBoardManager;
    Scene *mCurrectScene;

    int mWindowWidth;
    int mWindowHeight;

    bool mbReceivedExit;
};



#endif // SCENEMANAGER_H
