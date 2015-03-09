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
    static bool isIntersecting(Shape& mA, Shape& mB);
    static void testCollision(Paddle& mPaddle, Ball& mBall);
    static bool testCollision(Brick& mBrick, Ball& mBall);
};

