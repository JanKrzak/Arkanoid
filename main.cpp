#include "Game.h"
#include "Menu.h"

int main()
{
    Menu menu;
    while (!menu.isExitRequested())
    {
        menu.showMenu();
        if (menu.isStartRequested())
        {
            Game game;
            game.initGame();
            game.displayGame();
        }
    }
    return 0;
}
