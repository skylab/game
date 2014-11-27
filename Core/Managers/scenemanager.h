#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Infra/singleton.h"
#include "../Main/scene.h"

class SceneManager : public Singleton<SceneManager>
{
public:
    SceneManager();
    virtual ~SceneManager() override;

    bool LoadFirstScene(void);

    Scene *GetCurrentScene(void);
    void ChangeScene(Scene *scene);

    void DrawScene(void);
    void Reshape(int &width, int &height);

private:
    Scene *mCurrentScene;
};

#endif // SCENEMANAGER_H
