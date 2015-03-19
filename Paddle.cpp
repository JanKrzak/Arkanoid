#include "Paddle.h"

Paddle::Paddle(float positionX, float paddleWidth)
{
        shape.setPosition(positionX, windowHeight - 50);
        shape.setFillColor(sf::Color::Red);
        shape.setOrigin(paddleWidth / 2, paddleHeight / 2);
        shape.setSize( { paddleWidth, paddleHeight });
}

Paddle::~Paddle()
{

}

/*
 * \brief function provide paddle move
 */
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

/*
 * \brief function provide paddle x position
 */
float Paddle::x()
{
    return shape.getPosition().x;
}

/*
 * \brief function provide paddle y position
 */
float Paddle::y()
{
    return shape.getPosition().y;
}

/*
 * \brief function provide paddle left side position
 */
float Paddle::left()
{
    return x() - shape.getSize().x / 2.f;
}

/*
 * \brief function provide paddle right side position
 */
float Paddle::right()
{
    return x() + shape.getSize().x / 2.f;
}

/*
 * \brief function provide paddle top side position
 */
float Paddle::top()
{
    return y() - shape.getSize().y / 2.f;
}

/*
 * \brief function provide paddle bottom side position
 */
float Paddle::bottom()
{
    return y() + shape.getSize().y / 2.f;
}
