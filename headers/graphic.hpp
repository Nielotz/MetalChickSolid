#pragma once

#include "map.hpp"
#include "hero.hpp"


class Graphic
{
    Hero mHero;
public:
    // Save hero for further use.
    Graphic(const Hero &hero);

    // Load map to be displayed on the screen.
    void load_map(Map &map);

    // Draw the map around hero (his render view).
    void draw_map(Position &hero_position);

    // Draw the hero at the position.
    void draw_hero(Position &hero_position);

    // Draw fireworks and update stats.
    void increase_lvl();

    // Updates screen.
    void update();
};
