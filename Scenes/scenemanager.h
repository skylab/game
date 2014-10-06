#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Common/precommon.h"

#include "../GraphicSystem/pregraphic.h"

class Scene;

class SceneManager
{
public:
    ~SceneManager();

    static SceneManager *Instance(void);

    void ChangeScene(Scene *scene);

    Scene *GetCurrentScene(void);

    void SetWindow(GLFWwindow *window);
    const GLFWwindow *GetWindow(void) const;

    const int &GetWindowWidth(void) const;
    const int &GetWindowHeight(void) const;

    void DrawScene(void) const;
    void Reshape(int width, int height);
    void Keyboard(int &key);
    void MousePosition(double &xpos, double &ypos);

    void SimulateScene(void) const;

    void SetReceivedExit(bool val);
    const bool &GetReceivedExit(void) const;

private:
    SceneManager();

private:
    GLFWwindow *mWindow;
    Scene *mScene;

    int mWindowWidth;
    int mWindowHeight;

    bool mbReceivedExit;

    static SceneManager *mInstance;
};

#endif // SCENEMANAGER_H
