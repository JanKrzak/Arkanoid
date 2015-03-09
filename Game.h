#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Operations.h"
#include "Bonus.h"

class Game{
public:
    Game();
    virtual ~Game();
    void initGame();

private:
    bool isOver(Paddle& mPaddle, Ball& mBall) const;
    bool arebricksOver(Brick& bricks);
    void eraseBricks(Brick& brick, Ball& ball);
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
    sf::RenderWindow *window;

    bool _gameOver;
    bool _bricksOver;
    bool _bonus;
    float _paddleWidth;

    Ball ball;
    Paddle *paddle;
    Bonus *bonus;
    Brick bricks;
};

