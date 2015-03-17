#pragma once
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Shape.h"
#include "Bonus.h"
#include "Bullets.h"
#include "config.h"
#include <cmath>

class Operations{
public:
    static bool isIntersecting(Shape& shapeA, Shape& shapeB);
    static int testCollision(Paddle& paddle, Ball& ball);
    static bool testCollision(Brick& brick, Ball& ball);
    static bool testCollisionBullet(Brick& brick, Bullets& bullets);
    static void eraseBricks(Brick& bricks);
private:
    static void setCollisionCoordinates(Brick& brick, Ball& ball);
};
