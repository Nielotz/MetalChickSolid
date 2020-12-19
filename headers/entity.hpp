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

    int32_t fight_distance;
    int32_t attack_time;
    int32_t block_chance;
    int32_t dodge_chance;
    int32_t critic_hit_chance;

    // Fires when player hits movement controlling buttons. Probably W/A/S/D.
    // Return true when moved successfully.
    // TODO: When move fired, if is is possible - change the hero position.
    bool move(Direction &direction);
};