#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include "scene.h"

//First scene of the game
class LoadingScene : public Scene
{
public:
    LoadingScene();

    void Draw(void);
    void Keyboard(unsigned char &key, int &x, int &y);
};

#endif // LOADINGSCENE_H
