#pragma once

#include "position.hpp"

enum class TileType : uint8_t
{
    NPC = 1,
    ENEMY = 2,
    TERRAIN = 3,
    ITEM = 4
};

struct Tile
{
    TileType type;
    Position position;
    bool is_walkable;
    // Texture texture;
};