/*
 * Bullets.cpp
 *
 *  Created on: 16 mar 2015
 *      Author: krzacjan
 */

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

bool Bullets::time(int seconds)
{
    std::cout<<"CLOCK"<<std::endl;
        clock_t koniec_czekania;
        koniec_czekania = clock() + seconds * CLOCKS_PER_SEC;
        if( clock() < koniec_czekania )
        {
            return true;
        }
        return false;
}

bool Bullets::isInWindow()
{
    if (y() > 0)
    {
        return true;
    }
    return false;
}

/*
 * \brief function update bonus ball move
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
