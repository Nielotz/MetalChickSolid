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
	std::vector<StrPositionHeight> maps_data[4] = {
		{ // Test map.

		},{ // Start map.
			{"Bear_1", {5,5}, 2},
			{"Dragon_1", {7,5}, 2},
			{"Dragon_1", {7,8}, 2},

		},{ // Forest map.
			{"Bear_1", {5,5}, 2},
			{"Dragon_1", {7,5}, 2},
			{"Dragon_1", {3,5}, 4},
			{"Dragon_1", {2,2}, 5}

		},{ // Boss map.
			{"Bear_1", {5,5}, 2},
			{"Dragon_1", {7,5}, 2},
			{"Dragon_1", {7,5}, 2},
			{"Dragon_1", {7,5}, 2}

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