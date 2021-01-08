#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "hero.hpp"



class Graphic
{
    // Draw the map around hero (his render view).
    void draw_map();
    
    // Holds 
    sf::View map_view;

public:
    //Hero hero;
    std::unique_ptr<sf::RenderWindow> window;
    Map map;

    // Save hero for further use.
    Graphic();

    // Load level into the graphic.
    //
    // \param map: Map that will be displayed on the screen.
    // 
    void load_level(Map &map);
    
    // Load texture for the entity from the 
    void load_texture_for(Entity &entity, std::string path);

    // Draw the hero at the position.
    void draw_hero(Position &hero_position);

    // Draw fireworks and update stats.
    void increase_lvl();

    // Updates screen.
    void update();

    void move_hero(const Direction &direction);
};
