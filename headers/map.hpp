#pragma once

#include <vector>
#include <string>

#include "tile.hpp"

using std::vector;
using std::string;

struct Map
{
    vector<Tile> tiles;

    // Load the maps (textures, physical map) from the files.
    void load_maps(string &path);
    void load_maps(const char *path);
};