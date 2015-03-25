#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Operations.h"
#include "Bonus.h"
#include "Bullets.h"
#include "Level.h"
#include "TextHandle.h"

class Game{
public:
    Game(bool typeOfGame);
    ~Game();
    void initGame();
    void displayGame();

private:
    void drawBonus();
    void initBullets();
    int bulletOperation();
    void pauseGame();
    void testCollisionBrickAndBall();

    sf::Sprite sprite;
    sf::Texture texture;
    sf::RenderWindow *window;

    bool _bonus;
    bool _isMultiplayer;
    bool _pause;
    bool  _startShoot;

    float _paddleWidth;
    float _ballRadius;
    int _levelNumber;
    int _numberOfBricks;
    std::vector<Bullets> bulletsVector;

    sf::Clock clock;
    sf::Clock bulletClock;
    sf::Time time;
    sf::Time bulletReleaseTime;

    TextHandle text;
    Ball *ball;
    Paddle *paddle;
    Paddle *paddleMultiplayer;
    Bonus *bonus;
    Brick bricks;
    Bullets *bullets;
    Level level;
    Rank rank;


};

