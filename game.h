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
    bool Init();

private:
    Game();

private:
    static Game *mInstance;

    unsigned int mVisualArrayObject;
    SceneManager *mSceneManager;

    bool mbStarted;
};

#endif // GAME_H
