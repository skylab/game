#include "game.h";

int main()
{
    Game *game = Game::Instance();
    game->Execute();
    game->Remove();
    return 0;
}

