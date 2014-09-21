#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "scene.h"

class MainScene : public Scene
{
public:
    MainScene();
    ~MainScene();

    void Draw();
    void Keyboard(int &key);
    void MousePosition(double &xpos, double &ypos);
};

#endif // MAINSCENE_H
