#include "Game.h"

using namespace std;

Game::Game(bool typeOfGame):
         window(NULL),
        _bonus(false),
        _isMultiplayer(false),
        _pause(false),
        _startShoot(false),
        _paddleWidth(80.f),
        _ballRadius(10.f),
        _levelNumber(0),
        _numberOfBricks(0),
         ball(NULL),
         paddle(NULL),
         paddleMultiplayer(NULL),
         bonus(NULL),
         bullets(NULL)
{
    if (!texture.loadFromFile("background.png"))
    {
        std::cout << "Can't load background" << std::endl;
    }
    if(typeOfGame)
    {
        _isMultiplayer = true;
    }
}

Game::~Game()
{
    delete window;
}

/*
 * \brief function test collision between bullets and bricks
 */
int Game::bulletOperation()
{
    for (Brick& brick : bricks.getBricks())
    {
        for (Bullets& bulletsVect : bulletsVector)
        {
            if ((Operations::testCollisionBullet(brick, bulletsVect)))
            {
                text.initPoints(_numberOfBricks);
                Operations::eraseBricks(bricks);
                return 0;
            }
        }
    }
    return 0;
}

/*
 * \brief draw function initialize bullets. Create new objects and add to vector
 */
void Game::initBullets()
{
    time = clock.getElapsedTime();
    if ((time.asSeconds()) < 5)
    {
        bulletReleaseTime = bulletClock.getElapsedTime();
        if (bulletReleaseTime.asMilliseconds() > 500)
        {
            bullets = new Bullets(paddle->x(), paddle->y());
            bulletsVector.push_back(*bullets);
            bulletClock.restart();
        }
    }
    else
    {
        _startShoot = false;
        bulletsVector.clear();
    }
}

/*
 * \brief function draw bonus circle. It can give additional or negative paddle width or resize ball.
 */
void Game::drawBonus()
{
    float newSize = 0;
    float newRadius = 0;
    int bonusNumber = 0;
    if (bonus->isInWindow())
    {
        bonus->update();
        window->draw(bonus->shape);
        if (Operations::isIntersecting(*paddle, *bonus))
        {
            bonus->randomBonus(bonusNumber);
            if(bonusNumber == 1)
            {
                float paddlePositionX = paddle->x();
                delete paddle;
                bonus->changePaddleWidth(newSize);
                paddle = new Paddle(paddlePositionX, _paddleWidth += newSize, 50);
            }
            if(bonusNumber == 2)
            {
                float ballPositionX = ball->x();
                float ballPositionY = ball->y();
                delete ball;
                bonus->changeBallRadius(newRadius);
                ball = new Ball(_ballRadius += newRadius, ballPositionX, ballPositionY);
            }
            if(bonusNumber == 3)
            {
                delete bullets;
                bullets = new Bullets(paddle->x(), paddle->y());
                _startShoot = true;
                clock.restart();
                bulletClock.restart();
            }
            _bonus = false;
            delete bonus;
        }
    }
    else
    {
        delete bonus;
        _bonus = false;
    }
}

/*
 * \brief function pause game if key "P" is pressed
 */
void Game::pauseGame()
{
    static int pauseTemp = 0;
    pauseTemp++;
    if(pauseTemp % 2 == 0)
    {
        _pause = false;
    }
    else
    {
        _pause = true;
    }
}

/*
 * \brief function test collision between bricks and ball
 */
void Game::testCollisionBrickAndBall()
{
    for (Brick& brick : bricks.getBricks())
    {
        if (Operations::testCollision(brick, *ball))
        {
            text.initPoints(_numberOfBricks);
            if ((Bonus::randomChance()) && (!_bonus))
            {
                _bonus = true;
                bonus = new Bonus(*ball);
            }
        }
    }
}

/*
 * \brief function initialize elements of the game
*/
void Game::initGame()
{
    _levelNumber++;

    //Initialization new WIndow to display game
    if(_levelNumber == 1)
    {
    window = new sf::RenderWindow( { windowWidth, windowHeight }, "Arkanoid");
    window->setFramerateLimit(60);
    }

    paddle = new Paddle(windowWidth / 2, _paddleWidth, 50);

    if(_isMultiplayer)
    {
    paddleMultiplayer = new Paddle(windowWidth / 2, _paddleWidth, 550);
    }

    ball = new Ball(_ballRadius, windowWidth / 2, windowHeight / 2);

    bullets = new Bullets;

    if (_isMultiplayer)
    {
        level.initLevel(bricks, _levelNumber, 8);
    }
    else
    {
        level.initLevel(bricks, _levelNumber, 2);
    }

    //Initializing background texture
    sprite.setTexture(texture);

    //Initializing stats text to display
    text.initStats();

    level.displayLevel(_levelNumber, text.font, *window);
}

/*
 * \brief function display game
 */
void Game::displayGame()
{
    initGame();

    while (!Operations::isBallUnderPaddle(*ball, *paddle , *paddleMultiplayer, _isMultiplayer))
    {
        if (Operations::areBricksOver(bricks))
        {
            delete paddle;
            delete ball;
            delete bullets;
            _startShoot = false;
            bulletsVector.clear();
            initGame();
        }
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
            if ((event.type == sf::Event::KeyPressed)  && (event.key.code == sf::Keyboard::P))
            {
                pauseGame();
            }
        }
        if (!_pause)
        {
            window->clear();
            ball->update();
            paddle->update();

            window->draw(sprite);
            window->draw(text.stats);
            window->draw(text.points);
            window->draw(ball->shape);
            window->draw(paddle->shape);

            if (_isMultiplayer)
            {
                paddleMultiplayer->updateMultiplayer();
                window->draw(paddleMultiplayer->shape);
                Operations::testCollisionMultiplayer(*paddleMultiplayer, *ball);
            }

            //testing collision between paddle and ball
            Operations::testCollision(*paddle, *ball);

            //testing collision between all bricks and ball
            testCollisionBrickAndBall();

            if (_bonus)
            {
                drawBonus();
            }

            if (_startShoot)
            {
                initBullets();
                bulletOperation();
                Bullets::drawBullets(bulletsVector, *window);
            }

            //erase bricks when collision is detected
            Operations::eraseBricks(bricks);

            //draw bricks
            for (Brick& brick : bricks.getBricks())
            {
                window->draw(brick.shape);
            }
            window->display();
        }
    }
    delete paddle;
    delete paddleMultiplayer;
    delete ball;
    delete bullets;
    text.displayGameStats(*window, bricks);
    rank.checkRankResult(text.rankString, text.point);
}
