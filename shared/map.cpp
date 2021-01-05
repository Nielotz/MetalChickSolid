#include <iostream>

#include "../headers/map.hpp"
#include "../headers/consts.hpp"

void Map::load_texture(const char *path)
{
    name = path;
    load_texture(name);
}

void Map::load_texture(string &path)
{
    name = path;

    if (!texture.loadFromFile(path))
        throw std::runtime_error("Cannot load " + path);

    tiles_number = {
        texture.getSize().x / CONSTS::TILE_SIZE_ON_TEXTURE_MAP, 
        texture.getSize().y / CONSTS::TILE_SIZE_ON_TEXTURE_MAP };

    texture.setSmooth(true);
    sprite.setTexture(texture);
}
