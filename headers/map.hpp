#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "entity.hpp"

#include <vector>
#include <string>


using std::vector;
using std::string;

struct MapData
{
	// Includes doors, teleport points, etc.
	std::vector<Entity> entries;

	// Enemies.
	std::vector<Entity> entities;
	
	std::vector<Position> walls;

};

struct Map
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u tiles_number;

	Map(std::string& path_to_data_file);
	Map() = default;

	MapData* data;

	// Load the map (textures, physical map) from the files.
	void load_texture(string& path);
	void load_texture(const char* path);

	void load_map_data(string& path);
	void load_map_data(const char* path);
};