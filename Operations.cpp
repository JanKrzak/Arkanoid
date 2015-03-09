#include "Operations.h"

bool Operations::isIntersecting(Shape& mA, Shape& mB)
{
        return mA.right() >= mB.left() &&
               mA.left() <= mB.right() &&
               mA.bottom() >= mB.top() &&
               mA.top() <= mB.bottom();
}

/*
 * \brief function test if there is collision between paddle and ball
 * \details if there is collision, new ball velocity(x,y) will be initialize, based on angel of reflection
 */
void Operations::testCollision(Paddle& mPaddle, Ball& mBall)
{
    if (!isIntersecting(mPaddle, mBall))
    {
        return;
    }

    float v = sqrt((mBall.velocity.x * mBall.velocity.x) + (mBall.velocity.y * mBall.velocity.y));
    float width = mPaddle.right() - mPaddle.left();
    float nx;
    float ny;

    if (mBall.x() < mPaddle.x())
    {

        nx = cos((mPaddle.x() - mBall.x()) * (3.14 / 4) / (width / 2)) * v;
        ny = sin((mPaddle.x() - mBall.x()) * (3.14 / 4) / (width / 2)) * v;
        mBall.velocity.x = -nx;
        mBall.velocity.y = -ny;
    }
    else
    {
        nx = cos((mBall.x() - mPaddle.x()) * (3.14 / 4) / (width / 2)) * v;
        ny = sin((mBall.x() - mPaddle.x()) * (3.14 / 4) / (width / 2)) * v;
        mBall.velocity.x = nx;
        mBall.velocity.y = -ny;
    }
}

/*
 * \brief function test if there is collision between bricks and ball
 */
bool Operations::testCollision(Brick& mBrick, Ball& mBall)
{
    if (!isIntersecting(mBrick, mBall))
    {
        return false;
    }
    mBrick.destroyedBrick = true;

    float overlapLeft { mBall.right() - mBrick.left() };
    float overlapRight { mBrick.right() - mBall.left() };
    float overlapTop { mBall.bottom() - mBrick.top() };
    float overlapBottom { mBrick.bottom() - mBall.top() };

    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    float minOverlapX { ballFromLeft ? overlapLeft : overlapRight };
    float minOverLapY { ballFromTop ? overlapTop : overlapBottom };

    if (abs(minOverlapX) < abs(minOverLapY))
    {
        mBall.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
    }
    else
    {
        mBall.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
    }
    return true;
}
