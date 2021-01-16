#pragma once

#include "graphic.hpp"
#include "profile.hpp"
#include "control.hpp"
#include "map.hpp"
#include "arena.hpp"
#include "enemy.hpp"
#include "tuts.hpp"

class Game
{
public:

    // Main game loop. 
    //
    // Blocks thread.
    void game_loop();

    Game();
    bool is_running = true;

    void start();
    void stop();
    void exit();
    void start_tutorial();
    void load_map();

    void move_hero(const Direction& direction);
    void start_fight(Enemy& enemy);

private:
    Profile profile;
    Graphic graphic;
    Control control;
    Arena arena;
    Map map;

    std::vector<Enemy> enemies;

    bool can_hero_move(const Direction& direction);
    void choose_profile(Profile& profile);

};