#ifndef GAME_H
#define GAME_H

#include "GraphicSystem/graphicsystem.h"

class Game
{
public:
    static Game *Instance() throw();
    void Remove() throw();

    void Execute() throw();

    bool getIsStarted() const throw();
    void setIsStarted(bool value) throw();

private:
    Game() throw();
    ~Game() throw();
    bool Init() throw();

private:
    static Game *mInstance;
    GraphicSystem *mGraphicSystem;

    bool mIsStarted;
};

#endif // GAME_H
