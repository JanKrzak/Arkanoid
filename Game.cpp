#include "Game.h"

Game::Game():
         window(NULL),
        _gameOver(false),
        _bricksOver(false),
        _bonus(false),
        _paddleWidth(80.f),
         paddle(NULL),
         bonus(NULL)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Can't load font" << std::endl;
        _gameOver = true;
    }
}

Game::~Game()
{
    delete window;
}

/*
 * \brief function check if ball is not under paddle line. If it is then return false and game is end.
 */
bool Game::isOver(Paddle& mPaddle, Ball& mBall) const
{
    if (mBall.y() > mPaddle.y())
    {
        return true;
    }
    return false;
}

/*
 * \brief function check if there are any bricks left. If not its return false and game is end.
 */
bool Game::arebricksOver(Brick& bricks)
{
    if(bricks.getBricks().size() == 0)
        {
            return true;
        }
    return false;
}

/*
 * \brief function erase bricks when collision is detected
 */
void Game::eraseBricks(Brick& bricks, Ball& ball)
{
    bricks.getBricks().erase(remove_if(begin(bricks.getBricks()), end(bricks.getBricks()),
                    [](const Brick& mBrick) {return mBrick.destroyedBrick;}),
                        end(bricks.getBricks()));
}

/*
 * \brief function initialize stats text
 */
void Game::initStats(sf::Text& tekst)
{
    tekst.setString("Points:");
    tekst.setColor(sf::Color::Red);
    tekst.setFont(font);
    tekst.setCharacterSize(tekst.getCharacterSize());
    tekst.setPosition(580, 550);
}

/*
 * \brief function initialize points text
 * \param const int initialNumberOfBricks provide starting number of bricks
 */
void Game::initPoints(sf::Text& points, Brick& bricks, const int initialNumberOfBricks)
{
    std::stringstream ss;
    std::string point;

    int numberOfBricks = (initialNumberOfBricks - bricks.getBricks().size()) * 10;

    ss << numberOfBricks;
    ss >> point;
    points.setString(point);
    points.setColor(sf::Color::Red);
    points.setFont(font);
    points.setPosition(680, 550);
}

/*
 * \brief function initialize game over text
 */
void Game::gameOverStats(sf::Text& gameOver)
{
    gameOver.setString("Game Over!");
    gameOver.setColor(sf::Color::Red);
    gameOver.setFont(font);
    gameOver.setCharacterSize(64);
    gameOver.setPosition(220, 220);
}

/*
 * \brief function initialize text if you win a game
 */
void Game::gameWinStats(sf::Text& gameOver)
{
    gameOver.setString("Winner!");
    gameOver.setColor(sf::Color::Red);
    gameOver.setFont(font);
    gameOver.setCharacterSize(64);
    gameOver.setPosition(220, 220);
}

/*
 * \brief function display game stats
 */
void Game::displayGameStats()
{
    while (!_gameOver)
       {
           sf::Event eventOver;
           while(window->pollEvent(eventOver))
           {
               if (sf::Event::MouseButtonPressed)
               {
                   if (eventOver.mouseButton.button == sf::Mouse::Left)
                   {
                       _gameOver = true;
                       window->close();
                   }
               }
               if(sf::Event::KeyPressed)
               {
                   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                   {
                       _gameOver = true;
                       window->close();
                   }
               }
               if (eventOver.type == sf::Event::Closed)
               {
                   _gameOver = true;
                   window->close();
               }
           }
           sf::Text game;
           window->clear();
           if(arebricksOver(bricks))
           {
               gameWinStats(game);
           }
           else
           {
               gameOverStats(game);
           }
           window->draw(game);
           window->draw(stats);
           window->draw(points);
           window->display();

       }
    window->close();
}

/*
 * \brief function draw bonus circle. It can give additional or negative paddle width
 */
void Game::drawBonus()
{
    int newSize = 0;
    if (bonus->isInWindow())
    {
        bonus->update();
        window->draw(bonus->shape);
        if (Operations::isIntersecting(*paddle, *bonus))
        {
            float paddlePositionX = paddle->x();
            _bonus = false;
            delete bonus;
            if(bonus->randomChance())
            {
                newSize = 15;
            }
            else
            {
                newSize = -15;
            }
            paddle = new Paddle(paddlePositionX, _paddleWidth += newSize);
        }
    }
    else
    {
        delete bonus;
        _bonus = false;
    }
}

/*
 * \brief function initialize game and display it
 */
void Game::initGame()
{
    //Initialization new WIndow to display game
    window = new sf::RenderWindow( { windowWidth, windowHeight }, "Arkanoid");
    window->setFramerateLimit(60);

    paddle = new Paddle(windowWidth / 2, _paddleWidth);

    //Initializing bricks
    bricks.initBricks();

    const int initialNumberOfBricks = bricks.getBricks().size();

    //Initializing stats text to display
    initStats(stats);

    while (!isOver(*paddle, ball) && !arebricksOver(bricks))
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        window->clear();
        ball.update();
        paddle->update();

        //testing collision between paddle and ball
        Operations::testCollision(*paddle, ball);

        //testing collision between all bricks and ball
        for (Brick& brick : bricks.getBricks())
        {
            if (Operations::testCollision(brick, ball) && (Bonus::randomChance()) && (!_bonus))
            {
                      _bonus = true;
                       bonus = new Bonus(ball);
            }
        }
        if (_bonus)
        {
           drawBonus();
        }

        //erase bricks when detected collision
        eraseBricks(bricks, ball);

        //Initializing points text to display
        initPoints(points, bricks, initialNumberOfBricks);

        window->draw(stats);
        window->draw(points);
        window->draw(ball.shape);
        window->draw(paddle->shape);

        //draw bricks
        for (Brick& brick : bricks.getBricks())
        {
            window->draw(brick.shape);
        }
        window->display();
    }
    delete paddle;
    displayGameStats();
}
