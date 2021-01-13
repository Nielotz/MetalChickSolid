#include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>

#include "../headers/control.hpp"
#include "../headers/game.hpp"


void Control::parse_move_events(Graphic& graphic, Game& game)
{
    auto& now = std::chrono::steady_clock::now;

    std::chrono::steady_clock::time_point start = now();
    std::chrono::duration<double> duration;
    // Check all the window's events that were triggered since the last iteration of the loop.
    sf::Event event;
    while (graphic.window->pollEvent(event))
    {
        duration = now() - start;
        if (duration.count() > 0.1)
            break;

        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            graphic.window->close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::A)
            {
                game.move_hero(Direction::LEFT);
            }
            else if (event.key.code == sf::Keyboard::D)
            {
                game.move_hero(Direction::RIGHT);
            }
            else if (event.key.code == sf::Keyboard::W)
            {
                game.move_hero(Direction::TOP);
            }
            else if (event.key.code == sf::Keyboard::S)
            {
                game.move_hero(Direction::BOTTOM);
            }
        }
    }
}