#pragma once
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Shape.h"
#include "Bonus.h"
#include "config.h"
#include <cmath>

class Operations{
public:
    static bool isIntersecting(Shape& shapeA, Shape& shapeB);
    static int testCollision(Paddle& paddle, Ball& ball);
    static bool testCollision(Brick& brick, Ball& ball);
    static void eraseBricks(Brick& bricks);
};
