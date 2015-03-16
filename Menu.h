#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

enum GameState {GAME_START,EXIT};

class Menu {
public:
    Menu();
    ~Menu();
    GameState showMenu();

private:
    void initButton();
    void initBackground();

    sf::Text playText;
    sf::Text quitText;
    sf::Font font;
    sf::Texture textur;
    sf::Sprite sprite;
};


