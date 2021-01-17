#include <iostream>

#include "../headers/game.hpp"
#include "../headers/consts.hpp"
#include "../headers/enemy.hpp"

using std::clog;
using std::cout;
using std::endl;


void Game::game_loop()
{
	load_map(profile.hero.map_id);

	while (graphic.window->isOpen())
	{
		control.parse_walk_events(graphic, *this);

		graphic.update();
		graphic.window->display();
	}
	profile.save();
}


Game::Game() :
	graphic(Graphic(profile.hero))
{
	start();
	clog << "Initializing graphics..." << endl;
	game_loop();
};


void Game::start()
{
	cout << "Starting game." << endl;

	clog << "Choosing profile... " << profile.name << endl;
	choose_profile(profile);
	cout << "Chosen profile: " << profile.name << endl;


	clog << "Loading profile..." << endl;
	profile.load();
	clog << "Loaded profile, nick: " << profile.hero.name << endl;
	//clog << "lvl: "<< profile.hero.lvl<<"\nexp: " << profile.hero.exp << "\nhp: " << profile.hero.hp << "\nhp_max: " << profile.hero.hp_max << "\nmana: " << profile.hero.mana << "\nstamina: " << profile.hero.stamina << "\nstrength: " << profile.hero.strength << "\nagility: " << profile.hero.agility << "\nintelect: " << profile.hero.intelect << "\nblock: " << profile.hero.block << "\ndefence: " << profile.hero.defence << "\nAT: " << profile.hero.attack_time << "\n";

}

void Game::choose_profile(Profile& profile)
{
	profile.path = "test_profile.txt";
}

void Game::exit()
{
	graphic.window->close();
}

void Game::load_map(uint16_t map_id)
{
	std::string map_file;
	if (map_id == 0)
		map_file = PATH::MAP::TEXTURES::TEST;
	else if (map_id == 1)
		map_file = PATH::MAP::TEXTURES::START;
	else if (map_id == 2)
		map_file = PATH::MAP::TEXTURES::FOREST;
	// else if (map_id == 3)
	  //  map_file = PATH::MAP::TEXTURES::BOSS;

	uint8_t mob_height; // Set in if;
	std::string killed_mobs; // List of killed mobs from file.

	for (const StrPositionHeight& data : maps_data[map_id])
	{
		if (killed_mobs.find(data.name) == std::string::npos)
		{
			std::string texture_path;
			if (data.name.find("Bear") != std::string::npos)
			{
				texture_path = PATH::ENTITY_TEXTURES::BEAR::MAP;
				enemies.push_back(Bear());
			}
			else if (data.name.find("Deer") != std::string::npos)
			{
				texture_path = PATH::ENTITY_TEXTURES::DEER::MAP;
				enemies.push_back(Deer());
			}
			else if (data.name.find("Goblin") != std::string::npos)
			{
				texture_path = PATH::ENTITY_TEXTURES::GOBLIN::MAP;
				enemies.push_back(Goblin());
			}
			else if (data.name.find("Troll") != std::string::npos)
			{
				texture_path = PATH::ENTITY_TEXTURES::TROLL::MAP;
				enemies.push_back(Troll());
			}
			else if (data.name.find("Fox") != std::string::npos)
			{
				texture_path = PATH::ENTITY_TEXTURES::FOX::MAP;
				enemies.push_back(Fox());
			}
			else if (data.name.find("Dragon") != std::string::npos)
			{
				texture_path = PATH::ENTITY_TEXTURES::DRAGON::MAP;
				enemies.push_back(Dragon());
			}
			enemies[enemies.size() - 1].name = data.name;
			//enemies[enemies.size() - 1].update_stats(profile.hero.lvl - 1);

			graphic.load_enemy_texture(enemies[enemies.size() - 1], texture_path);
			enemies[enemies.size() - 1].position = data.pos;
			graphic.set_enemy_position(enemies[enemies.size() - 1], data.pos); // x, y
			graphic.set_enemy_size(enemies[enemies.size() - 1], 2);
		}

	}
		



	map.load_texture(map_file);
	map.load_map_collisions(map_file);

	graphic.load_level(map);

	graphic.set_hero_position(profile.hero.position);

	//Set player to center of screen
	for (int i = 0; i < 10; i++)
		graphic.update_view();
}

void Game::start_tutorial()
{
	while (graphic.window->isOpen())
	{
		control.parse_walk_events(graphic, *this);

		graphic.draw_tutorial();
		graphic.window->display();
	}
}

void Game::move_hero(const Direction& direction)
{
	if (graphic.is_hero_moving)
		return;

	if (can_hero_move(direction))
	{
		if (direction == Direction::LEFT)
		{
			graphic.move_hero(Direction::LEFT);
			profile.hero.position.x--;
		}
		else if (direction == Direction::RIGHT)
		{
			graphic.move_hero(Direction::RIGHT);
			profile.hero.position.x++;
		}
		else if (direction == Direction::TOP)
		{
			graphic.move_hero(Direction::TOP);
			profile.hero.position.y--;
		}
		else // BOTTOM
		{
			graphic.move_hero(Direction::BOTTOM);
			profile.hero.position.y++;
		}
	}
}

void Game::perform_fight(Enemy& enemy)
{
	auto hero_pos = profile.hero.position;
	auto enemy_pos = enemy.position;
	if (abs(hero_pos.x - enemy_pos.x) < 3 || abs(hero_pos.y - enemy_pos.y) < 3)
	{
		std::string path;
		Position enemy_position(11, 3);
		uint8_t height = 8;

		if (enemy.name.find("Bear") != std::string::npos)
			path = PATH::ENTITY_TEXTURES::BEAR::ARENA;
		else if (enemy.name.find("Deer") != std::string::npos)
			path = PATH::ENTITY_TEXTURES::DEER::ARENA;
		else if (enemy.name.find("Goblin") != std::string::npos)
			path = PATH::ENTITY_TEXTURES::GOBLIN::ARENA;
		else if (enemy.name.find("Troll") != std::string::npos)
			path = PATH::ENTITY_TEXTURES::TROLL::ARENA;
		else if (enemy.name.find("Fox") != std::string::npos)
			path = PATH::ENTITY_TEXTURES::FOX::ARENA;
		else if (enemy.name.find("Dragon") != std::string::npos)
		{
			path = PATH::ENTITY_TEXTURES::DRAGON::ARENA;
			height = 9;
			//enemy_position = Position();
		}
		else
			throw std::runtime_error("Enemy has to have name.");

		graphic.load_arena_enemy_texture(enemy, path);
		graphic.set_arena_enemy_position(enemy, enemy_position);
		graphic.set_arena_enemy_size(enemy, height);

		graphic.display_arena(enemy);

		graphic.update();
		graphic.window->display();

		arena.fight(profile.hero, enemy, graphic);
		while (!control.check_mouse_left_button_clicked(graphic))
		{
			graphic.update();
			graphic.window->display();
		}
	}
	graphic.display_map();
}

bool Game::can_hero_move(const Direction& direction)
{
	int32_t cords[2] = { 0,0 }; //y,x
	if (direction == Direction::LEFT)
	{
		cords[1] = -1;
	}
	else if (direction == Direction::RIGHT)
	{
		cords[1] = 1;
	}
	else if (direction == Direction::TOP)
	{
		cords[0] = -1;
	}
	else // BOTTOM
	{
		cords[0] = 1;
	}
	cords[0] += (int32_t)profile.hero.position.y;
	cords[1] += (int32_t)profile.hero.position.x;
	if ((cords[0] != -1 && cords[0] != 19) && (cords[1] != -1 && cords[1] != 22)) {
		if (map.collisions[cords[0]][cords[1]] == ' ')
			return true;
		else
			return false;
	}
	else return false;

}
