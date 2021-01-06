#include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>

#include "../headers/control.hpp"


void Control::parse_events(Graphic& graphic)
{
    // Check all the window's events that were triggered since the last iteration of the loop.
    sf::Event event;
    while (graphic.window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            graphic.window->close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::A)
            {
                graphic.move_hero(Direction::LEFT);
            }
            else if (event.key.code == sf::Keyboard::D)
            {
                graphic.move_hero(Direction::RIGHT);
            }
            else if (event.key.code == sf::Keyboard::W)
            {
                graphic.move_hero(Direction::TOP);
            }
            else if (event.key.code == sf::Keyboard::S)
            {
                graphic.move_hero(Direction::BOTTOM);
            }
        }
    }
}