#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Shape.h"
#include "Paddle.h"


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
    static void drawBullets(std::vector<Bullets>& bulletsVector, sf::RenderWindow& window);

    sf::CircleShape shape;
    sf::Vector2f velocity {0, -bulletVelocity};

};


