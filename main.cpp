#include "Game.h"
#include "Menu.h"

int main()
{
    Menu menu;
    int gameType = 0;
    while (gameType != 2)
    {
        gameType = menu.showMenu();
        Game game(gameType);
        if (gameType == 0)
        {
            game.displayGame();
        }
        else if(gameType == 1)
        {
            game.displayGame();
        }
    }
    return 0;
}
