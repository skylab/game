#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "sceneabs.h"

class MainScene : public SceneAbs
{
public:
    MainScene();
    ~MainScene() override;

    //void Draw(void) override;
    void Keyboard(int &key) override;
    void MousePosition(double &xpos, double &ypos) override;
};

#endif // MAINSCENE_H
