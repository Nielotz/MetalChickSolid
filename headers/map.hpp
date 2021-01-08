#pragma once

#include <vector>
#include <string>

#include "tile.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using std::vector;
using std::string;

enum class MapType : uint8_t
{
    TEST,
    HOME,
    VILLAGE

};

struct Map
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2u tiles_number;

    MapType map_type;

    // Load the map (textures, physical map) from the files.
    void load_texture(string &path);
    void load_texture(const char *path);

    Map();
};