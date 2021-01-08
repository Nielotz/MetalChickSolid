#pragma once

#include "position.hpp"
#include "profession.hpp"
#include "direction.hpp"
#include <string>

// Base for all entities.
struct Entity
{
    std::string name;
    Position position;
    ProfessionType profession_type;

    // Level related.
    int32_t lvl = 0;
    int32_t exp = 0;

    // Statistics.
    int32_t hp = 0; //current hp
    int32_t hp_max = 0; //max anvalible hp
    int32_t mana;
    int32_t stamina;
    int32_t aim;
    int32_t strength;
    int32_t agility;
    int32_t intelect;
    int32_t critical;
    int32_t critical_power;
    int32_t block;
    int32_t defence;
    int32_t attack_time;

    // Fires when player hits movement controlling buttons. Probably W/A/S/D.
    // Return true when moved successfully.
    // TODO: When move fired, if is is possible - change the hero position.
    bool move(Direction &direction);
};