#include "Rank.h"

using namespace std;

Rank::Rank():
    _numberOfRanksRecord(0)
{
    file.open( "rank.txt", std::ios::out | std::ios::app);
    if(!file.good())
       {
           std::cerr << "Can't open file" << std::endl;
       }
    file.close();
}

Rank::~Rank()
{

}

/*
 * \brief function read user points.
 */
int readPoints(std::string line)
{
    int points;
    stringstream ss;
    std::size_t position = line.find_last_of(" ");
    std::string temp = line.substr(position);
    ss << temp;
    ss >> points;
    return points;}

/*
 * \brief function read user name and points from file. Then add it to vector which contains users ranking
 */
void Rank::readRecords(string& rank)
{
    string line;
    string numberOfLine;
    stringstream ss[_numberOfRanksRecord];
    for(int i = 0; i < _numberOfRanksRecord; i++)
    {
        ss[i] << i + 1;
        ss[i] >> numberOfLine;
        getline(file, line);
        if(!line.empty())
        {
        rankVector.push_back(line);
        rank += numberOfLine + ". " + line + "\n";
        }
    }
}

/*
 * \brief function provide number of records which are stored in the file
 */
int Rank::numberOfRecords()
{
    int number = 0;
    file.open("rank.txt", std::ios::in);
    if (!file.good())
    {
        std::cerr << "Can't open file" << std::endl;
    }
    else
    {
        string line;
        while (!file.eof())
        {
            getline(file, line);
            number++;
        }
        file.close();
    }
    return number;
}

/*
 * \brief function sort records from highest to lowest
 */
void Rank::sortBetterResult()
{
    string temp;
    for (int i = 0; i < 25; i++)
    {
        for (unsigned j = 0; j < rankVector.size() - 1; j++)
        {
            if (readPoints(rankVector[j]) < readPoints(rankVector[j + 1]))
            {
                temp = rankVector[j];
                rankVector[j] = rankVector[j + 1];
                rankVector[j + 1] = temp;
            }
        }
    }
}

/*
 * \brief function initialize rank records to display
 */
void Rank::initRankToDisplay(string& rank)
{
    _numberOfRanksRecord = numberOfRecords();
    file.open("rank.txt", std::ios::in);
    if (!file.good())
    {
        std::cerr << "Can't open file" << std::endl;
    }
    else
    {
        readRecords(rank);
        file.close();
    }
}

/*
 * \brief function compares current record points of records contained in the file
 */
void Rank::compareResult(string point, string name)
{
    string newRecord;
    string temp;
    _numberOfRanksRecord = numberOfRecords();

    rankVector.clear();

    file.open("rank.txt", std::ios::in);
    if (file.good())
    {
        if (_numberOfRanksRecord < 6)
        {
            readRecords(temp);
            newRecord = name + " " + point;
            rankVector.push_back(newRecord);
            sortBetterResult();
        }
        else
        {
            readRecords(temp);
            newRecord = name + " " + point;
            rankVector.push_back(newRecord);
            sortBetterResult();
            rankVector.pop_back();
        }
        file.close();
    }
    else
    {
        std::cerr << "Can't open file" << std::endl;
    }
}

/*
 * \brief function save records to file
 */
void Rank::saveToFile()
{
    file.open("rank.txt", std::ios::out);
    if (file.good())
    {
        for (unsigned i = 0; i < rankVector.size(); i++)
        {
            file << rankVector[i] << std::endl;
        }
        file.close();
    }
    else
    {
        std::cerr << "Can't open file" << std::endl;
    }

}

/*
 * \brief function check if user provide name.
 */
void Rank::checkRankResult(sf::String rankString, string point)
{
    if(!rankString.isEmpty())
    {
       compareResult(point, rankString);
       saveToFile();
    }
}
