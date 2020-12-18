#pragma once

#include "position.hpp"
#include "profession.hpp"
#include "direction.hpp"

// Base for all entities.
struct Entity
{
    Position position;
    ProfessionType profession_type;

    // Level related.
    int32_t lvl = 0;
    int32_t exp = 0;

    // Statistics.
    int32_t hp = 0;
    int32_t hit = 0;

    // Fires when player hits movement controlling buttons. Probably W/A/S/D.
    // Return true when moved successfully.
    // TODO: When move fired, if is is possible - change the hero position.
    bool move(Direction &direction);

};