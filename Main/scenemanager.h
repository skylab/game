#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../GraphicSystem/pregraphic.h"

class SceneAbs;

class SceneManager
{
public:
    ~SceneManager();

    static SceneManager *Instance(void);

    void SwitchScene(Scene *scene);
    SceneAbs *GetCurrentScene(void);

    void SetWindow(GLFWwindow *window);
    const GLFWwindow *GetWindow(void) const;

    void SetWindowWidth(size_t width);
    const int &GetWindowWidth(void) const;
    void SetWindowHeight(size_t height) const;
    const int &GetWindowHeight(void) const;

    void DrawScene(void) const;
    void Reshape(int width, int height);
    void Keyboard(int &key);
    void MousePosition(double &xpos, double &ypos);

    void SetReceivedExit(bool val);
    const bool &GetReceivedExit(void) const;

private:
    SceneManager();

private:
    GLFWwindow *mWindow;
    SceneAbs *mScene;

    int mWindowWidth;
    int mWindowHeight;

    bool mbReceivedExit;



#endif // SCENEMANAGER_H
