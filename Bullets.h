#pragma once
#include "Shape.h"
#include <iostream>

class Bullets: public Shape{
public:
    Bullets();
   // Bullets( const Bullets & bullets);
    Bullets(float positionX, float positionY);
    ~Bullets();
    void update();

    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();

    bool time(int seconds);
    bool isInWindow();
    bool destroyedBullet{false};

    sf::CircleShape shape;
    sf::Vector2f velocity {0, -bulletVelocity};
};


