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

    setStartVelocity();
}

Ball::~Ball()
{

}

/*
 * \brief function set velocity and angle of starting position ball
 */
void Ball::setStartVelocity()
{
    srand(time(NULL));
    float randomVelocityX = (rand() % 300 ) + 100;
    float randomSide = (rand() % 4);
    float v = sqrt((ballVelocity * ballVelocity) + (ballVelocity * ballVelocity));

    float ny = cos((randomVelocityX) * (3.14 / 4) / (windowHeight / 2)) * v;

    if(randomSide > 1)
    {
        float nx = sin((randomVelocityX) * (3.14 / 4) / (windowWidth / 2)) * v;
        velocity = {nx,-ny};
    }
    else
    {
        float nx = sin((randomVelocityX) * (3.14 / 4) / (windowWidth / 2)) * v;
        velocity = {-nx,-ny};
    }

}

/*
 * \brief function provide ball move
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
