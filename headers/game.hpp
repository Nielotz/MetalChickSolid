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
    void game_loop();

    Game();
    bool is_running = true;

    void start();
    void stop();
    void exit();

    void move_hero(const Direction& direction);
private:
    Profile profile;
    Graphic graphic;
    Control control;
    Arena arena;
    Map map;

    char mapakolizji1[18][21] = {
    "###########   ######",
    "#########      #####",
    "######         #####",
    "####           #####",
    "#####           ####",
    "#####             ##",
    "#####             ##",
    "#####     #     ####",
    "#####     #     ####",
    "#####     #     ####",
    "###       #       ##",
    "###                #",
    "##                  ",
    "####                ",
    "####      #     ####",
    "#######   ##########",
    "####################",
    "####################"
    };

    void choose_profile(Profile& profile);

};