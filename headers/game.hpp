#pragma once

#include "graphic.hpp"
#include "profile.hpp"
#include "control.hpp"
#include "map.hpp"
#include "arena.hpp"
#include "enemy.hpp"

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

    std::vector<Enemy> enemies;

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