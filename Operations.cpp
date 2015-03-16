#include "Operations.h"

/*
 * \brief function test if shapes are intersecting each others.
 * \return true if shapes touch each others
 */
bool Operations::isIntersecting(Shape& shapeA, Shape& shapeB)
{
    if(shapeA.right() >= shapeB.left() &&  shapeA.left() <= shapeB.right() &&
       shapeA.bottom() >= shapeB.top() &&  shapeA.top() <= shapeB.bottom())
    {
        return true;
    }
    return false;
}

/*
 * \brief function test if there is collision between paddle and ball
 * \details if there is collision, new ball velocity(x,y) will be initialize, based on angel of reflection
 */
int Operations::testCollision(Paddle& paddle, Ball& ball)
{
    if (!isIntersecting(paddle, ball))
    {
        return 0;
    }

    float v = sqrt((ball.velocity.x * ball.velocity.x) + (ball.velocity.y * ball.velocity.y));
    float width = paddle.right() - paddle.left();
    float nx;
    float ny;

    if (ball.x() < paddle.x())
    {
        nx = sin((paddle.x() - ball.x() + 1) * (3.14 / 4) / (width / 2)) * v;
        ny = cos((paddle.x() - ball.x() + 1) * (3.14 / 4) / (width / 2)) * v;
        ball.velocity.x = -nx;
        ball.velocity.y = -ny;
    }
    else
    {
        nx = sin((ball.x() - paddle.x() + 1) * (3.14 / 4) / (width / 2)) * v;
        ny = cos((ball.x() - paddle.x() + 1) * (3.14 / 4) / (width / 2)) * v;
        ball.velocity.x = nx;
        ball.velocity.y = -ny;
    }
    return 0;
}

/*
 * \brief function test if there is collision between bricks and ball
 */
bool Operations::testCollision(Brick& brick, Ball& ball)
{
    if (!isIntersecting(brick, ball))
    {
        return false;
    }
    brick.destroyedBrick = true;

    float overlapLeft { ball.right() - brick.left() };
    float overlapRight { brick.right() - ball.left() };
    float overlapTop { ball.bottom() - brick.top() };
    float overlapBottom { brick.bottom() - ball.top() };

    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    float minOverlapX { ballFromLeft ? overlapLeft : overlapRight };
    float minOverLapY { ballFromTop ? overlapTop : overlapBottom };

    if (abs(minOverlapX) < abs(minOverLapY))
    {
        ball.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
    }
    else
    {
        ball.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
    }
    return true;
}

/*
 * \brief function erase bricks when collision is detected
 */
void Operations::eraseBricks(Brick& bricks)
{
    bricks.getBricks().erase(remove_if(begin(bricks.getBricks()), end(bricks.getBricks()),
                    [](const Brick& mBrick) {return mBrick.destroyedBrick;}),
                        end(bricks.getBricks()));
}
