#include "Brick.h"

Brick::Brick():
_originPosX(0),
_originPosY(0)
{

}

Brick::Brick(float positionX, float positionY)
{
    _originPosX = blockWidth / 2.f;
    _originPosY = blockHeight / 2.f;
    shape.setPosition(positionX, positionY);
    shape.setSize( { blockWidth, blockHeight });
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin(_originPosX, _originPosY);
}

Brick::~Brick()
{

}

/*
 * \brief function provide brick x position
 */
float Brick::x()
{
    return shape.getPosition().x;
}

/*
 * \brief function provide brick y position
 */
float Brick::y()
{
    return shape.getPosition().y;
}

/*
 * \brief function provide brick left side position
 */
float Brick::left()
{
    return x() - shape.getSize().x / 2.f;
}

/*
 * \brief function provide brick right side position
 */
float Brick::right()
{
    return x() + shape.getSize().x / 2.f;
}

/*
 * \brief function provide brick top side position
 */
float Brick::top()
{
    return y() - shape.getSize().y / 2.f;
}

/*
 * \brief function provide brick bottom side position
 */
float Brick::bottom()
{
    return y() + shape.getSize().y / 2.f;
}

/*
 * \brief function initialize bricks in right order
 */
void Brick::initBricks(int numberOfX, int numberOfY)
{
    for (int i = 0; i < numberOfX; i++)
    {
        for (int j = 0; j < numberOfY; j++)
        {
            _bricks.emplace_back((i + 1) * (blockWidth + 3) + 22,
                    (j + 2) * (blockHeight + 3));
        }
    }
}
