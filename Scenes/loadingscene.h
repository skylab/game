#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include "scene.h"

//First scene of the game
class LoadingScene : public Scene
{
public:
    LoadingScene();

    void Draw(void);
    void Keyboard(int &key);
};

#endif // LOADINGSCENE_H
