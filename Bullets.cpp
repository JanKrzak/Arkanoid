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

/*
 * \brief function erase bullets which hit bricks
 */
void eraseBullet(std::vector<Bullets>& bulletsVector)
{
    bulletsVector.erase(remove_if(begin(bulletsVector), end(bulletsVector),
                    [](const Bullets& mBullet) {return mBullet.destroyedBullet;}),
                        end(bulletsVector));
}

/*
 * \brief function draw bullets shape
 */
void Bullets::drawBullets(std::vector<Bullets>& bulletsVector, sf::RenderWindow& window)
{
    for (Bullets& bulletsVect : bulletsVector)
    {
        if (!bulletsVect.destroyedBullet && bulletsVect.isInWindow())
        {
            bulletsVect.update();
            window.draw(bulletsVect.shape);
        }
        else
        {
            eraseBullet(bulletsVector);
        }
    }
}

/*
 *\brief function check if bullets is in window
 */
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
