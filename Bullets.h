#pragma once
#include "Shape.h"

class Bullets: public Shape{
public:
    Bullets();
    Bullets(float positionX, float positionY);
    ~Bullets();

    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();
    void update();
    bool isInWindow();
    bool destroyedBullet{false};

    sf::CircleShape shape;
    sf::Vector2f velocity {0, -bulletVelocity};
};


