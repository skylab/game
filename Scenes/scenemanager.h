#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Common/precommon.h"

class Scene;

class SceneManager
{
public:
    ~SceneManager();

    static SceneManager *Instance(void);

    void ChangeScene(Scene *scene);

    //
    Scene *GetCurrentScene(void);

    void DrawScene(void) const;
    void Reshape(int width, int height);
    void Keyboard(unsigned char &key, int &x, int &y);
    void Mouse(int &key, int &state, int &x, int &y);

    void SimulateScene(void) const;

private:
    SceneManager();

private:
    static SceneManager *mInstance;

    Scene *mScene;
};

#endif // SCENEMANAGER_H
