#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

// To work with GLFW
#include "../GraphicSystem/pregraphic.h"

#include "Objects/sceneobject.h"
#include "Objects/cameraobject.h"

class SceneManager
{
public:
    ~SceneManager();

    static SceneManager *Instance(void);

    bool StartScenes(void);
    void ChangeScene(SceneObject *scene);
    SceneObject *GetCurrentScene(void);

    void SetWindow(GLFWwindow *window);
    const GLFWwindow *GetWindow(void) const;

    void SetWindowWidth(size_t width);
    const int &GetWindowWidth(void) const;

    void SetWindowHeight(size_t height);
    const int &GetWindowHeight(void) const;

    void SetReceivedExit(bool val);
    const bool &GetReceivedExit(void) const;

    // Drawing tools
    void DrawScene(void) const;
    void Reshape(int width, int height);
    void Keyboard(int &key, int &scancode, int &action, int &mods);
    void MousePosition(double &xpos, double &ypos);

private:
    SceneManager();

private:
    static SceneManager *mInstance;
    GLFWwindow *mWindow;
    SceneObject *mScene;

    int mWindowWidth;
    int mWindowHeight;

    bool mbReceivedExit;
};



#endif // SCENEMANAGER_H
