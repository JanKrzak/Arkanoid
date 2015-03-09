#include "Brick.h"

Brick::Brick()
{

}

Brick::Brick(float mX, float mY)
{
    shape.setPosition(mX, mY);
    shape.setSize( { blockWidth, blockHeight });
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
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

void Brick::initBricks()
{
    for (int i = 0; i < countBlocksX; i++)
    {
        for (int j = 0; j < countBlocksY; j++)
        {
            _bricks.emplace_back((i + 1) * (blockWidth + 3) + 22,
                    (j + 2) * (blockHeight + 3));
        }
    }
}
