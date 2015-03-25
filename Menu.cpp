#include "Menu.h"

using namespace std;

Menu::Menu()
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
    playText.setOrigin(35,0);
    playText.setString("SINGLEPLAYER");

    mutliplayer.setFont(font);
    mutliplayer.setCharacterSize(16);
    mutliplayer.setOrigin(30,0);
    mutliplayer.setString("MULTIPLAYER");

    quitText.setFont(font);
    quitText.setCharacterSize(16);
    quitText.setString("QUIT");

}

/*
 * \brief function initialize background
 */
void Menu::initBackground()
{
    if (!textur.loadFromFile("Arkanoid.png"))
    {
        cout<<"Can't load textures"<<endl;
    }
    sprite.setScale(1,1.5);
    sprite.setOrigin(-70,0);
    sprite.setTexture(textur);
}

/*
 * \brief function display game menu
 */
GameState Menu::showMenu()
{
    string ranking;

    //initialize button
    initButton();

    Button play(200, 200, 400, 40, playText, sf::Color(128, 128, 128));
    Button multiplayer(200, 250, 400, 40, mutliplayer, sf::Color(128, 128, 128));
    Button quit(200, 300, 400, 40, quitText, sf::Color(128, 128, 128));


    //initialize window to display menu
    sf::RenderWindow window(sf::VideoMode(800,600), "Arkanoid");
    window.setFramerateLimit(30);

    //initialize background
    initBackground();

    //initialize ranking text and points to display
    rank.initRankToDisplay(ranking);
    text.initRankText();
    text.initRankPoints(ranking);

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
            if (multiplayer.above(event))
            {
                multiplayer.changeAboveBackground();
            }
            else
            {
                multiplayer.resetAboveBackground();
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
                return EXIT;
                window.close();
            }
            if(sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                    if (play.click(mousePosition))
                    {
                        window.close();
                        return GAME_START;
                    }
                    if(multiplayer.click(mousePosition))
                    {
                        window.close();
                        return MULTIPLAYER_START;
                    }
                    if (quit.click(mousePosition))
                    {
                        window.close();
                        return EXIT;
                    }
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return EXIT;
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(play);
        window.draw(multiplayer);
        window.draw(quit);
        text.displayRank(window);
        window.display();
   }
   return EXIT;
}
