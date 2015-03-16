#include "Game.h"
#include "Menu.h"

int main()
{
    Menu menu;
    while (menu.showMenu() != 1)
    {
        if (menu.showMenu() == 0)
        {
            Game game;
            game.initGame();
            game.displayGame();
        }
    }
    return 0;
}
