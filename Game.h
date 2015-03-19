#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "Operations.h"
#include "Bonus.h"
#include "Bullets.h"

class Game{
public:
    Game();
    ~Game();
    void initGame();
    void displayGame();

private:
    bool isBallUnderPaddle(Paddle& paddle, Ball& ball) const;
    bool areBricksOver(Brick& bricks) const;
    void eraseBricks(Brick& brick);
    void initStats(sf::Text& tekst);
    void initPoints(sf::Text& points, Brick& bricks, const int initialNumberOfBricks);
    void gameOverStats(sf::Text& gameOver);
    void gameWinStats(sf::Text& gameOver);
    void displayGameStats();
    void initBonus();
    void drawBonus();
    void intiBullets();
    int bulletOperation();
    void drawBullets();
    void eraseBullet();

    sf::Font font;
    sf::Text stats;
    sf::Text points;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::RenderWindow *window;

    bool _gameOver;
    bool _bricksOver;
    bool _bonus;
    float _paddleWidth;
    float _ballRadius;
    bool  _startShoot;

    sf::Clock clock;
    sf::Clock bulletClock;
    sf::Time time;
    sf::Time bulletReleaseTime;

    Ball *ball;
    Paddle *paddle;
    Bonus *bonus;
    Brick bricks;
    Bullets *bullets;
    std::vector<Bullets> bulletsVector;
};

