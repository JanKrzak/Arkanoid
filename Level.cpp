/*
 * Level.cpp
 *
 *  Created on: 19 mar 2015
 *      Author: krzacjan
 */

#include "Level.h"

using namespace std;

Level::Level():
     _displayLevel(true)
{

}

Level::~Level()
{

}

/*
 * \brief function initialize level 1
 */
void level1(Brick& bricks, int brickDistance)
{
    //Initializing bricks
    bricks.initBricks(11, 4, brickDistance);
}

/*
 * \brief function initialize level 2
 */
void level2(Brick& bricks, int brickDistance)
{
    //Initializing bricks
    bricks.initBricks(11, 5, brickDistance);
}

/*
 * \brief function initialize level 3
 */
void level3(Brick& bricks, int brickDistance)
{
    //Initializing bricks
    bricks.initBricks(11, 6, brickDistance);
}

/*
 * \brief function initialize level 3
 */
void level4(Brick& bricks, int brickDistance)
{
    //Initializing bricks
    bricks.initBricks(11, 7, brickDistance);
}

/*
 * \brief function initialize level 3
 */
void level5(Brick& bricks, int brickDistance)
{
    //Initializing bricks
    bricks.initBricks(11, 8, brickDistance);
}

/*
 * \brief function initialize levels
 */
void Level::initLevel(Brick& bricks, int level, int brickDistance)
{
    if(level == 1)
    {
        level1(bricks, brickDistance);
    }
    if(level == 2)
    {
        level2(bricks, brickDistance);
    }
    if(level == 3)
    {
        level3(bricks, brickDistance);
    }
    if(level == 4)
    {
        level4(bricks, brickDistance);
    }
    if(level == 5)
    {
        level5(bricks, brickDistance);
    }

}


/*
 * \brief function display level text
 */
void Level::displayLevel(int levelNumber, sf::Font& font, sf::RenderWindow& window)
{
    sf::Text level;

    //initialize level text
    TextHandle::initLevelText(level, levelNumber, font);

    while (_displayLevel)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (((sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) || (event.type == sf::Event::Closed))
            {
                _displayLevel = false;
            }
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                _displayLevel = false;
            }
        }
        window.clear();
        window.draw(level);
        window.display();
    }
    _displayLevel = true;
}
