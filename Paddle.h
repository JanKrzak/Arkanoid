#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Shape.h"


class Paddle : public Shape {
public:
    Paddle(float mX, float paddleWidth);
    virtual ~Paddle();
    void update();
    void setSize();
    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();

    sf::RectangleShape shape;
    sf::Vector2f velocity;

};

