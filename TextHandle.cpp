#include "TextHandle.h"

using namespace std;

TextHandle::TextHandle():
        _display(false)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Can't load font" << std::endl;
    }

}

TextHandle::~TextHandle()
{

}

/*
 * \brief function initialize stats text
 */
void TextHandle::initStats()
{
    stats.setString("Points:");
    stats.setColor(sf::Color::Red);
    stats.setFont(font);
    stats.setCharacterSize(stats.getCharacterSize());
    stats.setPosition(580, 550);
}

/*
 * \brief function initialize points text
 */
void TextHandle::initPoints(int& numberOfBricks)
{
    std::stringstream ss;
    numberOfBricks += 10;
    ss << numberOfBricks;
    ss >> point;
    points.setString(point);
    points.setColor(sf::Color::Red);
    points.setFont(font);
    points.setPosition(680, 550);
}

/*
 * \brief function initialize game over text
 */
void TextHandle::gameOverStats()
{
    game.setString("Game Over!");
    game.setColor(sf::Color::Red);
    game.setFont(font);
    game.setCharacterSize(64);
    game.setPosition(220, 220);
}

/*
 * \brief function initialize wining text
 */
void TextHandle::gameWinStats()
{
    game.setString("Winner!");
    game.setColor(sf::Color::Red);
    game.setFont(font);
    game.setCharacterSize(64);
    game.setPosition(220, 220);
}

/*
 * \brief function initialize Ranking text
 */
void TextHandle::initEnterNameText()
{
    enterName.setString("Enter Name: ");
    enterName.setColor(sf::Color::Red);
    enterName.setFont(font);
    enterName.setCharacterSize(32);
    enterName.setPosition(220, 320);
}

/*
 * \brief function initialize ranking stats
 */
void TextHandle::initRankInput()
{
    ranking.setString(rankString);
    ranking.setColor(sf::Color::Red);
    ranking.setFont(font);
    ranking.setCharacterSize(32);
    ranking.setPosition(420, 320);
}

/*
 * \brief function initialize Ranking text
 */
void TextHandle::initRankText()
{
    rankDisplay.setString("Ranking: ");
    rankDisplay.setColor(sf::Color::Red);
    rankDisplay.setFont(font);
    rankDisplay.setCharacterSize(32);
    rankDisplay.setPosition(650, 170);
}

/*
 * \brief function initialize ranking points
 */
void TextHandle::initRankPoints(string ranking)
{
    string points;
    rankPoints.setString(ranking);
    rankPoints.setColor(sf::Color::Red);
    rankPoints.setFont(font);
    rankPoints.setCharacterSize(24);
    rankPoints.setPosition(650, 220);

}

/*
 * \brief function initialize level text
 */
void TextHandle::initLevelText(sf::Text& level, int levelNumber, sf::Font& font)
{
    stringstream ss;
    ss << levelNumber;
    string number = ss.str();
    std::string name = "level " + number;
    level.setString(name);
    level.setColor(sf::Color::Red);
    level.setFont(font);
    level.setCharacterSize(64);
    level.setPosition(310, 220);
}

/*
 * \brief function display game stats
 */
void TextHandle::displayGameStats(sf::RenderWindow& window, Brick& bricks)
{
    initEnterNameText();
    while (!_display)
       {
           sf::Event eventOver;
           while(window.pollEvent(eventOver))
           {
               if (((eventOver.type == sf::Event::MouseButtonPressed) && (eventOver.mouseButton.button == sf::Mouse::Left)) ||
                   (eventOver.type == sf::Event::Closed))
               {
                   _display = true;
                   window.close();
               }
               if (eventOver.type == sf::Event::TextEntered)
               {
                   if (eventOver.text.unicode < 128)
                   {
                       rankName += static_cast<char>(eventOver.text.unicode);
                       rankString = rankName;
                   }
                   initRankInput();
               }
               if((sf::Event::KeyPressed) && (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)))
               {
                   rankName.pop_back();
                   rankString = rankName;
               }
            }

           window.clear();
           if(Operations::areBricksOver(bricks))
           {
               gameWinStats();
           }
           else
           {
               gameOverStats();
           }
           window.draw(game);
           window.draw(stats);
           window.draw(points);
           window.draw(ranking);
           window.draw(enterName);
           window.display();
       }
    window.close();
}

/*
 * \brief function display rank text and rank points
 */
void TextHandle::displayRank(sf::RenderWindow& window)
{
    window.draw(rankDisplay);
    window.draw(rankPoints);
}
