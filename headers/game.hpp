#pragma once

#include "graphic.hpp"
#include "profile.hpp"
#include "control.hpp"
#include "map.hpp"
#include "arena.hpp"

class Game
{
public:

    // Main game loop. 
    //
    // Blocks thread.
    void dummy_game_loop();

    Game();
    bool is_running = true;

    void start();
    void stop();
private:
    Profile profile;
    Graphic graphic;
    Control control;
    Arena arena;
    Map map;

    Profile choose_profile();
};