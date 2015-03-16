#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "Operations.h"
#include "Bonus.h"

class Game{
public:
    Game();
    ~Game();
    void initGame();
    void displayGame();

private:
    bool isOver(Paddle& paddle, Ball& ball) const;
    bool arebricksOver(Brick& bricks) const;
    void eraseBricks(Brick& brick);
    void initStats(sf::Text& tekst);
    void initPoints(sf::Text& points, Brick& bricks, const int initialNumberOfBricks);
    void gameOverStats(sf::Text& gameOver);
    void gameWinStats(sf::Text& gameOver);
    void displayGameStats();
    void initBonus();
    void drawBonus();

    sf::Font font;
    sf::Text stats;
    sf::Text points;
    sf::Sprite sprite;
    sf::RenderWindow *window;

    bool _gameOver;
    bool _bricksOver;
    bool _bonus;
    float _paddleWidth;
    float _ballRadius;

    Ball *ball;
    Paddle *paddle;
    Bonus *bonus;
    Brick bricks;
};

