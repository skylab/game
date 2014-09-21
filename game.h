#ifndef GAME_H
#define GAME_H

#include "GraphicSystem/pregraphic.h"

class SceneManager;

class Game
{
public:
    static Game *Instance();
    ~Game();
    void Execute();

private:
    Game();

private:
    static Game *mInstance;

    unsigned int mVisualArrayObject;

    GLFWwindow* window;

    SceneManager *mSceneManager;
};

#endif // GAME_H
