#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "hero.hpp"



class Graphic
{
    // Check can view move to the direction.
    bool can_view_move(const Direction& direction);

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
    
    // Load texture for the entity from the 
    void load_texture_for(Entity &entity, std::string path);

    void load_hero_texture();

    // Draw the hero at the position.
    void draw_hero();

    // Draw fireworks and update stats.
    void increase_lvl();

    // Updates screen.
    void update();

    void move_hero(const Direction &direction);
};
