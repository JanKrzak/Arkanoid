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

/*
 * \brief function draws probability of a bonus
 */
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

/*
 * \brief function check if bonus ball is in game window
 */
bool Bonus::isInWindow()
{
    return (y() < windowHeight);
}

void Bonus::bullets()
{

}
/*
 * \brief function change paddle weight
 */
void Bonus::changePaddleWidth(float& newSize)
{
    srand(time(NULL));
    int randomNumber = rand() % 2;
    if(randomNumber == 1)
    {
        newSize = 15;
    }
    if(randomNumber == 2)
    {
        newSize = -15;
    }
}

/*
 * \brief function change ball radius
 */
void Bonus::changeBallRadius(float& radius)
{
    srand(time(NULL));
    int randomNumber = rand() % 2;
    if (randomNumber == 1)
    {
        radius = -2;
    }
    if(randomNumber == 2)
    {
        radius = 2;
    }
}

/*
 * \brief function draws a number of bonus
 */
void Bonus::randomBonus(int& bonusNumber)
{
    srand(time(NULL));
    int randomNumber = rand() % 4;
    if (randomNumber == 1)
    {
        bonusNumber = 1;
    }
    else if (randomNumber == 2)
    {
        bonusNumber = 2;
    }
    else if (randomNumber == 3)
    {
        bonusNumber = 3;
    }

}

/*
 * \brief function provide bonus ball move
 */
void Bonus::update()
{
    shape.move(velocity);
}

/*
 * \brief function provide bonus ball x position
 */
float Bonus::x()
{
    return shape.getPosition().x;
}

/*
 * \brief function provide bonus ball y position
 */
float Bonus::y()
{
    return shape.getPosition().y;
}

/*
 * \brief function provide bonus ball left side position
 */
float Bonus::left()
{
    return x() - shape.getRadius();
}

/*
 * \brief function provide bonus ball right side position
 */
float Bonus::right()
{
    return x() + shape.getRadius();
}

/*
 * \brief function provide bonus ball top side position
 */
float Bonus::top()
{
    return y() - shape.getRadius();
}

/*
 * \brief function provide bonus ball bottom side position
 */
float Bonus::bottom()
{
    return y() + shape.getRadius();
}

