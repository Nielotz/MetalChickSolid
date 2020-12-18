#pragma once

#include "profile.hpp"
#include "graphic.hpp"
#include "control.hpp"
#include "arena.hpp"
#include "item.hpp"

class Game
{
    void main_loop();

    /// Ask for profile and load it.
    Profile choose_profile();

public:
    bool is_running = true;

    /// Manage the hero profile.
    Profile profile;

    /// Handle stuff related to visual things.
    Graphic graphic;

    /// Control reactions to user inputs.
    Control control;

    /// Allow to perform fights.
    Arena arena;

    /// Store actual played and displayed map.
    Map map;

    /// Load profile and start infinite game loop.
    void start();

    /// Called when game ends.
    void stop();

    /// param graphic: Graphic object responsible for visual stuff.
    Game();

};