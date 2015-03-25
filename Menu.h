#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "TextHandle.h"
#include "Rank.h"

enum GameState {GAME_START, MULTIPLAYER_START, EXIT};

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
    sf::Text mutliplayer;
    sf::Font font;
    sf::Texture textur;
    sf::Sprite sprite;

    TextHandle text;
    Rank rank;
};


