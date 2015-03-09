#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

class Menu {
public:
    Menu();
    virtual ~Menu();
    void showMenu();
    bool isGameStart() const;
    bool getIsExit() const;

private:
    void initButton();
    void initBackground();
    sf::Text playText;
    sf::Text quitText;
    sf::Font font;
    sf::Texture textur;
    sf::Sprite sprite;
    sf::Clock clock;
    bool _isGameStart;
    bool _isExit;

};


