#include "game.h"

int main()
{
    Game *game = Game::Instance();
    if (nullptr != game)
    {
        if (game->Init())
            game->Execute();
        game->~Game();
    }
    return 0;
}

