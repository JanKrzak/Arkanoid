#pragma once
#include "Brick.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include "TextHandle.h"

class Level {
public:
    Level();
    virtual ~Level();
    void initLevel(Brick& bricks, int level, int brickDistance);
    void displayLevel(int levelNumber, sf::Font& font, sf::RenderWindow& window);

private:
     bool _displayLevel;
};
