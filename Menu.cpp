#include "Menu.h"

using namespace std;

Menu::Menu():
    _isGameStart(false),
    _isExit(false)
{
    if (!font.loadFromFile("arial.ttf"))
    {
           std::cout << "Can't load font" << std::endl;
    }
}

Menu::~Menu()
{
}

/*
 * \brief function initialize button with font, size and text
 */
void Menu::initButton()
{
    playText.setFont(font);
    playText.setCharacterSize(16);
    playText.setString("PLAY");

    quitText.setFont(font);
    quitText.setCharacterSize(16);
    quitText.setString("QUIT");
}

/*
 * \brief function return the value of _isGameStart
 */
bool Menu::isStartRequested() const
{
    return _isGameStart;
}

/*
 * \brief function return the value of _isExit
 */
bool Menu::isExitRequested() const
{
    return _isExit;
}

/*
 * \brief function initialize background
 */
void Menu::initBackground()
{

    if (!textur.loadFromFile("Arkanoid.png"))
    {
        cout<<"Can't load texturs"<<endl;
    }
    sprite.setScale(1,1.5);
    sprite.setOrigin(-70,0);
    sprite.setTexture(textur);
}

/*
 * \brief function display game menu
 */
void Menu::showMenu()
{
    //initialize button
    initButton();

    Button play(200, 200, 400, 40, playText, sf::Color(128, 128, 128));
    Button quit(200, 250, 400, 40, quitText, sf::Color(128, 128, 128));

    //initialize window to display menu
    sf::RenderWindow window(sf::VideoMode(800,600), "Arkanoid");
    window.setFramerateLimit(30);

    //initialize background
    initBackground();

    while (window.isOpen())
    {
        sf::Vector2f mousePosition(sf::Mouse::getPosition(window));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (play.above(event))
            {
                play.changeAboveBackground();
            }
            else
            {
                play.resetAboveBackground();

            }
            if (quit.above(event))
            {
                 quit.changeAboveBackground();
            }
            else
            {
                 quit.resetAboveBackground();

            }
            if(sf::Event::Closed)
            {
                _isExit = true;
                window.close();
            }
            if(sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (play.click(mousePosition))
                    {
                        _isGameStart = true;
                        window.close();
                    }
                    if (quit.click(mousePosition))
                    {
                        _isGameStart = false;
                        _isExit = true;
                        window.close();
                    }
                }
            }
            if(sf::Event::KeyPressed)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    _isGameStart = true;
                    window.close();
                }
            }
            if (event.type == sf::Event::Closed)
            {
                _isExit = true;
                window.close();
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(play);
        window.draw(quit);
        window.display();
   }

}
