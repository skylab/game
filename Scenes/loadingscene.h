#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include "scene.h"

//First scene of the game
class LoadingScene : public Scene
{
public:
    LoadingScene();

    void Draw(void) override;
    void Keyboard(int &key) override;
};

#endif // LOADINGSCENE_H
