#include "game.h"

int main()
{
    Game *game = Game::Instance();
    //game->Execute();
    game->~Game();
    return 0;
}

