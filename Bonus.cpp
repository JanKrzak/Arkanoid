#include "Bonus.h"

using namespace std;

Bonus::Bonus(Ball& ball):
        _x(ball.x()),
        _y(ball.y())
{
    shape.setRadius(bonusBallRadius);
    shape.setFillColor(sf::Color(150, 50, 250));
    shape.setPosition(_x, _y);
}

Bonus::~Bonus()
{

}

bool Bonus::randomChance()
{
    srand(time(NULL));
    int randomNumber = rand() % 10;
    if(randomNumber > 5)
    {
        return true;
    }
    return false;
}

bool Bonus::isInWindow()
{
    if (y() < windowHeight)
    {
        return true;
    }
    else
    {
        return false;

    }
    return false;
}

void Bonus::changePaddleWeight(float& newSize)
{
    if(randomChance())
    {
        newSize = 15;
    }
    else
    {
        newSize = -15;
    }
}

void Bonus::changeBallRadius(float& radius)
{
    if (randomChance())
    {
        radius = -2;
    }
    else
    {
        radius = 2;
    }
}

void Bonus::randomBonus(int& bonusNumber)
{
    if (randomChance())
    {
        bonusNumber = 1;
    }
    else
    {
        bonusNumber = 2;
    }
}

void Bonus::update()
{
    shape.move(velocity);
}
float Bonus::x()
{
    return shape.getPosition().x;
}
float Bonus::y()
{
    return shape.getPosition().y;
}
float Bonus::left()
{
    return x() - shape.getRadius();
}
float Bonus::right()
{
    return x() + shape.getRadius();
}
float Bonus::top()
{
    return y() - shape.getRadius();
}
float Bonus::bottom()
{
    return y() + shape.getRadius();
}

