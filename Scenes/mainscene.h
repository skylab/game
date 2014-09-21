#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "scene.h"

class MainScene : public Scene
{
public:
    MainScene();
    ~MainScene();

    void Draw();
    void Keyboard(unsigned char &key, int &x, int &y);
};

#endif // MAINSCENE_H
