#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

class Menu {
public:
    Menu();
    ~Menu();
    void showMenu();
    bool isStartRequested() const;
    bool isExitRequested() const;

private:
    void initButton();
    void initBackground();

    sf::Text playText;
    sf::Text quitText;
    sf::Font font;
    sf::Texture textur;
    sf::Sprite sprite;

    bool _isGameStart;
    bool _isExit;

};


