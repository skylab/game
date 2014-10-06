#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "scene.h"

class MainScene : public Scene
{
public:
    MainScene();
    ~MainScene();

    void Draw(void) override;
    void Keyboard(int &key) override;
    void MousePosition(double &xpos, double &ypos) override;
};

#endif // MAINSCENE_H
