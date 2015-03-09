#pragma once
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable
{
public:
    Button(unsigned short, unsigned short, unsigned short, unsigned short, sf::Text, sf::Color);
    ~Button();
    bool above(sf::Event);
    bool click(sf::Vector2f mousePosition);
    void changeAboveBackground();
    void resetAboveBackground();

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    unsigned short _x, _y, _width, _height;
    sf::Text text;
    sf::RectangleShape button;
    sf::Color color;

};

