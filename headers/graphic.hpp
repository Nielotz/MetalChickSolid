#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "hero.hpp"



class Graphic
{
    // Try to keep hero in the center of the view.
    void move_view(const Direction& direction);

    // Draw the map around hero (his render view).
    void draw_map();
    
    // Holds 
    sf::View map_view;

    Map map;
    std::shared_ptr<Hero> hero;

public:
    //Hero hero;
    std::unique_ptr<sf::RenderWindow> window;
    

    // Save hero for further use.
    Graphic(Hero &hero);

    // Load level into the graphic.
    //
    // \param map: Map that will be displayed on the screen.
    // 
    void load_level(Map &map);

    void load_hero_texture();

    // Draw the hero at the position.
    void draw_hero();

    // Draw fireworks and update stats.
    void increase_lvl();

    // Updates screen.
    void update();

    void move_hero(const Direction &direction);
};
