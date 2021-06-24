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
    void load_map(uint16_t map_id);

    void move_hero(const Direction& direction);
    void perform_fight(Enemy& enemy);

private:

    struct StrPositionHeight
    {
        const std::string name;
        const Position pos;
        const uint8_t height;

        StrPositionHeight(const std::string name, const Position pos, const uint8_t height)
            :name(name), pos(pos), height(height)
        {}
    };

    // Name (have to contain class name), position, height.
    const std::vector<StrPositionHeight> maps_data[4] = {
        { // Test map.

        },{ // Start map.
            {"Bear_1", {6,4}, 2},
            {"Deer_1", {12,8}, 2},
            {"Deer_2", {13,13}, 2},

        },{ // Forest map.
            {"Bear_1", {5,10}, 2},
            {"Deer_1", {7,5}, 2},
            {"Deer_1", {10,2}, 2},
            {"Troll_1", {13,7}, 2},
            {"Goblin_1", {7,12}, 2},
            {"Fox_1", {16,14}, 2},


        },{ // Boss map.
            {"Fox_1", {16,7}, 2},
            {"Dragon_1", {5,2}, 2},
            {"Goblin_1", {6,8}, 2},
            {"Troll_1", {9,14}, 2}

        },

    };

    Profile profile;
    Graphic graphic;
    Control control;
    Arena arena;
    Map map;

    std::vector<Enemy> enemies;

    bool can_hero_move(const Direction& direction);
    void choose_profile(Profile& profile);
};