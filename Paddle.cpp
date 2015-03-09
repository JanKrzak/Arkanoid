#include "Paddle.h"

Paddle::Paddle(float mX, float paddleWidth)
{
        shape.setPosition(mX, windowHeight -50);
        shape.setFillColor(sf::Color::Red);
        shape.setOrigin(paddleWidth / 2, paddleHeight / 2);
        shape.setSize( { paddleWidth, paddleHeight });
}

Paddle::~Paddle()
{

}

void Paddle::update()
{
    shape.move(velocity);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
    {
        velocity.x = -paddleVelocity;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)  && right() < windowWidth)
    {
        velocity.x = paddleVelocity;
    }
    else
    {
        velocity.x = 0;
    }
}

float Paddle::x()
{
    return shape.getPosition().x;
}
float Paddle::y()
{
    return shape.getPosition().y;
}
float Paddle::left()
{
    return x() - shape.getSize().x / 2.f;
}
float Paddle::right()
{
    return x() + shape.getSize().x / 2.f;
}
float Paddle::top()
{
    return y() - shape.getSize().y / 2.f;
}
float Paddle::bottom()
{
    return y() + shape.getSize().y / 2.f;
}
