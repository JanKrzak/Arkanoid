#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Shape.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


class Bonus: public Shape{
public:
    Bonus(Ball& ball);
    virtual ~Bonus();
    void getBallPosition(Ball& ball);
    void update();
    void randomBonus(int& bonusNumber);
    void changePaddleWidth(float& newSize);
    void changeBallRadius(float& radius);
    void bullets();
    bool isInWindow();
    static bool randomChance();

    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();

    sf::CircleShape shape;
    sf::Vector2f velocity {0, bonusVelocity};

private:
    float _x;
    float _y;





};


