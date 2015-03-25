#include "Operations.h"

/*
 * \brief function test if shapes are intersecting each others.
 * \return true if shapes touch each others
 */
bool Operations::isIntersecting(Shape& shapeA, Shape& shapeB)
{
    return shapeA.right() >= shapeB.left() &&  shapeA.left() <= shapeB.right() &&
       shapeA.bottom() >= shapeB.top() &&  shapeA.top() <= shapeB.bottom();
}

/*
 * \brief function check if there are any bricks left. If not its return false and game is end.
 */
bool Operations::areBricksOver(Brick& bricks)
{
    return bricks.getBricks().size() == 0;
}

/*
 * \brief function check if ball is not under paddle line. If it is then return false and game is end.
 */
bool Operations::isBallUnderPaddle(Ball& ball, Paddle& paddle, Paddle& paddleMultiplayer, bool& _isMultiplayer)
{
    if(_isMultiplayer)
    {
        return (ball.y() > paddle.y()) || (ball.y() < paddleMultiplayer.y()-10);
    }
    else
    {
        return ball.y() > paddle.y();
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
        nx = sin((paddle.x() - ball.x() + 10) * (3.14 / 4) / (width / 2)) * v;
        ny = cos((paddle.x() - ball.x() + 10) * (3.14 / 4) / (width / 2)) * v;
        ball.velocity.x = -nx;
        ball.velocity.y = -ny;
    }
    else
    {
        nx = sin((ball.x() - paddle.x() + 10) * (3.14 / 4) / (width / 2)) * v;
        ny = cos((ball.x() - paddle.x() + 10) * (3.14 / 4) / (width / 2)) * v;
        ball.velocity.x = nx;
        ball.velocity.y = -ny;
    }
    return 0;
}

/*
 * \brief function test if there is collision between paddle and ball in multiplayer mode
 * \details if there is collision, new ball velocity(x,y) will be initialize, based on angel of reflection
 */
int Operations::testCollisionMultiplayer(Paddle& paddleMultiplayer, Ball& ball)
{
    if (!isIntersecting(paddleMultiplayer, ball))
    {

        return 0;
    }

    float v = sqrt((ball.velocity.x * ball.velocity.x) + (ball.velocity.y * ball.velocity.y));
    float width = paddleMultiplayer.right() - paddleMultiplayer.left();
    float nx;
    float ny;

    if (ball.x() < paddleMultiplayer.x())
    {
        nx = sin((paddleMultiplayer.x() - ball.x() + 10) * (3.14 / 4) / (width / 2)) * v;
        ny = cos((paddleMultiplayer.x() - ball.x() + 10) * (3.14 / 4) / (width / 2)) * v;
        ball.velocity.x = -nx;
        ball.velocity.y = ny;
    }
    else
    {
        nx = sin((ball.x() - paddleMultiplayer.x() + 10) * (3.14 / 4) / (width / 2)) * v;
        ny = cos((ball.x() - paddleMultiplayer.x() + 10) * (3.14 / 4) / (width / 2)) * v;
        ball.velocity.x = nx;
        ball.velocity.y = ny;
    }
    return 0;
}

/*
 * \brief function set ball velocity after collision
 */
void setVelocityAfterCollision(Brick& brick, Ball& ball)
{
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
}

/*
 * \brief function test if there is collision between bricks and ball
 */
bool Operations::testCollision(Brick& brick, Ball& ball)
{
    bool isColliding = isIntersecting(brick, ball);
    if (isColliding)
    {
        setVelocityAfterCollision(brick, ball);
    }
    return isColliding;
}


/*
 * \brief function test if there is collision between bricks and bullets
 */
bool Operations::testCollisionBullet(Brick& brick, Bullets& bullets)
{
    if (!isIntersecting(brick, bullets))
    {
        return false;
    }
    bullets.destroyedBullet = true;
    brick.destroyedBrick = true;

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
