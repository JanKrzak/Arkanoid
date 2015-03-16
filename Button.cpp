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

/*
 * \brief SFML function converted into the operation of these buttons
 */
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(button, states);
    target.draw(text, states);
}

/*
 * \brief function check if mouse is above button
 * \sf::Event event - sfml event
 * \return true if mouse is above button and false otherwise
 */
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

/*
 * \brief function checks if the button was pressed
 * \sf::Vector2f mousePosition - provide mouse x and y position
 * \return this function return true if button was pressed and false otherwise
 */
bool Button::click(sf::Vector2f mousePosition)
{
    if ((mousePosition.x > _x) && (mousePosition.x < _x + _width)
            && (mousePosition.y > _y) && (mousePosition.y < _y + _height))
    {
        return true;
    }
    return false;
}

/*
 * \brief function change background color of button
 */
void Button::changeAboveBackground()
{
    button.setFillColor(sf::Color::Blue);
}

/*
 * \brief function reset background color of button to default
 */
void Button::resetAboveBackground()
{
    button.setFillColor(sf::Color(128, 128, 128));
}

