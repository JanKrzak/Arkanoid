#include "Brick.h"

Brick::Brick():
originPosX(0),
originPosY(0)
{

}

Brick::Brick(float positionX, float positionY)
{
    originPosX = blockWidth / 2.f;
    originPosY = blockHeight / 2.f;
    shape.setPosition(positionX, positionY);
    shape.setSize( { blockWidth, blockHeight });
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin(originPosX, originPosY);
}

Brick::~Brick()
{

}

float Brick::x()
{
    return shape.getPosition().x;
}
float Brick::y()
{
    return shape.getPosition().y;
}
float Brick::left()
{
    return x() - shape.getSize().x / 2.f;
}
float Brick::right()
{
    return x() + shape.getSize().x / 2.f;
}
float Brick::top()
{
    return y() - shape.getSize().y / 2.f;
}
float Brick::bottom()
{
    return y() + shape.getSize().y / 2.f;
}

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
