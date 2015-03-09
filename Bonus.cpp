#include "Bonus.h"

using namespace std;

Bonus::Bonus(Ball& ball):
        _x(ball.x()),
        _y(ball.y())
{
    shape.setRadius(ballRadius);
    shape.setFillColor(sf::Color(150, 50, 250));
    shape.setPosition(_x, _y);
}

Bonus::~Bonus()
{

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

