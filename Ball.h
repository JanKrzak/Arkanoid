#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Shape.h"


class Ball: public Shape
{
public:
    Ball();
    virtual ~Ball();

    void update();
    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();

    sf::CircleShape shape;
    sf::Vector2f velocity {-ballVelocity, -ballVelocity};
};


