#include "game.h"

int main()
{
    Game *game = Game::Instance();
    game->~Game();
    return 0;
}

