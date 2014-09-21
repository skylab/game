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
    static SceneManager *mInstance;
    Scene *mScene;
    GLFWwindow *mWindow;
    bool mbReceivedExit;
};

#endif // SCENEMANAGER_H
