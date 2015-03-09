#include "Game.h"
#include "Menu.h"

int main()
{
    Menu menu;
    while (!menu.getIsExit())
    {
        menu.showMenu();
        if (menu.isGameStart())
        {
            Game game;
            game.initGame();
        }
    }
    return 0;
}
