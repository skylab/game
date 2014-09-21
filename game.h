#ifndef GAME_H
#define GAME_H

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

    SceneManager *mSceneManager;
};

#endif // GAME_H
