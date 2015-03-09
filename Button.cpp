#include "Button.h"

Button::Button(unsigned short x, unsigned short y, unsigned short width,
        unsigned short height, sf::Text Ctext, sf::Color color):
        _x(x),
        _y(y),
        _width(width),
        _height(height),
        text(Ctext)
{
    button.setPosition(sf::Vector2f(x, y));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(color);
    text.setPosition(sf::Vector2f(x + width / 2, y + height / 3));
}

Button::~Button()
{

}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(button, states);
    target.draw(text, states);
}

bool Button::above(sf::Event event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        if ((event.mouseMove.x > _x) && (event.mouseMove.x < _x + _width)
             && (event.mouseMove.y > _y)  && (event.mouseMove.y < _y + _height))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool Button::click(sf::Vector2f mousePosition)
{
    if ((mousePosition.x > _x) && (mousePosition.x < _x + _width)
            && (mousePosition.y > _y) && (mousePosition.y < _y + _height))
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

void Button::changeAboveBackground()
{
    button.setFillColor(sf::Color::Blue);
}

void Button::resetAboveBackground()
{
    button.setFillColor(sf::Color(128, 128, 128));
}

