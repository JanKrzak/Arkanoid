#include "Ball.h"

Ball::Ball(float radius, float positionX, float positionY)
{
    if(radius < 2)
    {
        radius = 2;
    }
    shape.setPosition(positionX, positionY);
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Red);
}

Ball::~Ball()
{

}

/*
 * \brief function update ball move
 */
void Ball::update()
{
    shape.move(velocity);

    if (left() < 0)
    {
        velocity.x = ballVelocity;
    }
    else if (right() > windowWidth)
    {
        velocity.x = -ballVelocity;
    }
    if (top() < 0)
    {
        velocity.y = ballVelocity;
    }
    else if (bottom() > windowHeight)
    {
        velocity.y = -ballVelocity;
    }
}

/*
 * \brief function provide ball x position
 */
float Ball::x()
{
    return shape.getPosition().x;
}

/*
 * \brief function provide ball y position
 */
float Ball::y()
{
    return shape.getPosition().y;
}

/*
 * \brief function provide ball left side position
 */
float Ball::left()
{
    return x() - shape.getRadius();
}

/*
 * \brief function provide ball right side position
 */
float Ball::right()
{
    return x() + shape.getRadius();
}

/*
 * \brief function provide ball top side position
 */
float Ball::top()
{
    return y() - shape.getRadius();
}

/*
 * \brief function provide ball bottom side position
 */
float Ball::bottom()
{
    return y() + shape.getRadius();
}
