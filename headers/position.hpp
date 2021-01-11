#pragma once

#include <cstdint>


// Holds position data.
struct Position
{
    int32_t x = -1;
    int32_t y = -1;

    Position(int32_t x, int32_t y);
    Position() = default;
};
