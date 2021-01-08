#pragma once

#include "entity.hpp"
#include "hero.hpp"

#include <cstdint>


struct Enemy : Entity
{
    ///Status (dead, alive)
    int8_t staus;

    Enemy();
};

