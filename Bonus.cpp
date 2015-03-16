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
    cout<<"Bonus: "<<randomNumber<<endl;
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

/*
 * \brief function change paddle weight
 */
void Bonus::changePaddleWidth(float& newSize)
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

/*
 * \brief function change ball radius
 */
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

/*
 * \brief function draws a number of bonus
 */
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

/*
 * \brief function update bonus ball move
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

