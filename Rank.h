#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class Rank {
public:
    Rank();
    ~Rank();
    void compareResult(std::string point, std::string name);
    void checkRankResult(sf::String rankString, std::string point);
    void initRankToDisplay(std::string& rank);

private:
    void sortBetterResult();
    int numberOfRecords();
    void saveToFile();
    void readRecords(std::string& rank);

    int _numberOfRanksRecord;
    std::fstream file;
    std::vector<std::string> rankVector;
};


