#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "../pregraphic.h"

#include "sceneabs.h"

class MenuScene : public SceneAbs
{
public:
    MenuScene();
    ~MenuScene();

    virtual void DrawScene() const;

    virtual void KeyBoard(unsigned char &key, int &x, int &y);
};

#endif // MENUSCENE_H
