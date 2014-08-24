#ifndef GAME_H
#define GAME_H

#include "GraphicSystem/graphicsystem.h"

class Game
{
public:
    static Game *Instance();
    void Remove();

    void Execute();

    bool getIsStarted() const;
    void setIsStarted(bool value);

private:
    Game();
    ~Game();
    bool Init();

private:
    static Game *mInstance;
    GraphicSystem *mGraphicSystem;

    bool mIsStarted;
};

#endif // GAME_H
