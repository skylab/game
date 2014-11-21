#ifndef GAME_H
#define GAME_H

class SceneManager;
class Game
{
public:
    Game();
    ~Game();

private:
    bool Init();
    void Execute();

    // Scene manager implement logic of work with all scenes
    SceneManager *mSceneManager;

    bool mbStarted;
};

#endif // GAME_H
