#pragma once

#include <vector>
#include <string>

#include "tile.hpp"


struct Map
{
    std::vector<Tile> tiles;

    // Load the maps (textures, physical map) from the files.
    void load_maps(std::string &path);
    void load_maps(const char *path);
};