#pragma once
#include "Operations.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include "Rank.h"
#include "TextHandle.h"

class TextHandle {
public:
    TextHandle();
    ~TextHandle();
    void initStats();
    void initPoints(int& numberOfBricks);
    void displayGameStats(sf::RenderWindow& window, Brick& bricks);
    void displayRank(sf::RenderWindow& window);
    void initRankPoints(std::string ranking);
    static void initLevelText(sf::Text& level, int levelNumber, sf::Font& font);
    void gameOverStats();
    void initRankText();

    sf::Text points;
    sf::Text stats;
    sf::Font font;
    sf::String rankString;
    std::string rankName;
    std::string point;

private:
   void initRankInput();
   void checkRankResult();
   void gameWinStats();
   void initEnterNameText();

   bool _display;

   sf::Text ranking;
   sf::Text rankDisplay;
   sf::Text rankPoints;
   sf::Text enterName;
   sf::Text game;

   Rank rank;
};

