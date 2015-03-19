#pragma once
#include "Shape.h"


class Paddle : public Shape {
public:
    Paddle(float positionX, float paddleWidth);
    virtual ~Paddle();
    void update();
    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();

    sf::RectangleShape shape;
    sf::Vector2f velocity;
};

