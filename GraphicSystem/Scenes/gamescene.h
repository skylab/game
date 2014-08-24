#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../pregraphic.h"
#include "sceneabs.h"

class GameScene : public SceneAbs
{
public:
    GameScene();

    virtual void DrawScene() const;
    virtual void KeyBoard(unsigned char &key, int &x, int &y);
};

#endif // GAMESCENE_H
