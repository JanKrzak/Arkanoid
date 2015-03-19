#pragma once
#include <vector>
#include "Shape.h"

class Brick : public Shape
{
public:
    Brick();
    Brick(float positionX, float positionY);
    virtual ~Brick();
    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();
    void initBricks(int numberOfX, int numberOfY);
    bool destroyedBrick{false};
    std::vector<Brick>& getBricks()
    {
       return _bricks;
    }

     sf::RectangleShape shape;

private:
    std::vector<Brick> _bricks;
};

