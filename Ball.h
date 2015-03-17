#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Shape.h"
#include <cmath>
#include <ctime>


class Ball: public Shape
{
public:
    Ball(float radius, float positionX, float positionY);
    virtual ~Ball();

    void update();
    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();

    sf::CircleShape shape;
    sf::Vector2f velocity;


};



