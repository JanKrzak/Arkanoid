#include "Bullets.h"

Bullets::Bullets()
{

}
Bullets::Bullets(float positionX, float positionY)
{
    shape.setRadius(bulletRadius);
    shape.setFillColor(sf::Color(100, 30, 200));
    shape.setPosition(positionX, positionY);
}

Bullets::~Bullets()
{

}


bool Bullets::isInWindow()
{
    return (y() > 0);
}

/*
 * \brief function provide bonus ball move
 */
void Bullets::update()
{
    shape.move(velocity);
}

/*
 * \brief function provide bonus ball x position
 */
float Bullets::x()
{
    return shape.getPosition().x;
}

/*
 * \brief function provide bonus ball y position
 */
float Bullets::y()
{
    return shape.getPosition().y;
}

/*
 * \brief function provide bonus ball left side position
 */
float Bullets::left()
{
    return x() - shape.getRadius();
}

/*
 * \brief function provide bonus ball right side position
 */
float Bullets::right()
{
    return x() + shape.getRadius();
}

/*
 * \brief function provide bonus ball top side position
 */
float Bullets::top()
{
    return y() - shape.getRadius();
}

/*
 * \brief function provide bonus ball bottom side position
 */
float Bullets::bottom()
{
    return y() + shape.getRadius();
}
