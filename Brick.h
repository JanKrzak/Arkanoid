#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

class Brick : public Shape
{
public:
    Brick();
    Brick(float mX, float mY);
    virtual ~Brick();
    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();
    void initBricks();
    bool destroyedBrick{false};
    std::vector<Brick>& getBricks()
    {
       return _bricks;
    }

     sf::RectangleShape shape;

private:
    std::vector<Brick> _bricks;

};

