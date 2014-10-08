#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include "sceneabs.h"

class LoadingScene : public SceneAbs
{
public:
    LoadingScene();

    void Keyboard(int &key) override;
};

#endif // LOADINGSCENE_H
