#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "entity.hpp"

#include <vector>
#include <string>


using std::vector;
using std::string;

struct Map
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2u tiles_number;

    std::vector<std::string> collisions;
    std::vector<std::string> dead_enemies;

    Map(std::string& path_to_data_file);
    Map() = default;

    // Load the map (textures, physical map) from the files.
    void load_texture(string& path);
    void load_texture(const char* path);

    void load_map_data(string& path);
    void load_map_data(const char* path);
    void load_map_collisions(string& path);
    void save_load_dead_enemies();
};