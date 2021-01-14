#pragma once

#include "position.hpp"
#include "profession.hpp"
#include "direction.hpp"
#include "unique.hpp"

#include <string>
#include <string>

// Base for all entities.
struct Entity : Unique
{
    std::string name;
    Position position = { 0, 0 };
    ProfessionType profession_type = ProfessionType::NONE;

    // Level related.
    int32_t lvl = 0;
    int32_t exp = 0;

    // Statistics.
    int32_t hp = 0; // current hp
    int32_t hp_max = 0; // max avalible hp
    int32_t mana = 0;
    int32_t stamina = 0;
    int32_t strength = 0;
    int32_t agility = 0;
    int32_t intelect = 0;
    int32_t critical = 0;
    int32_t critical_power = 0;
    int32_t block = 0;
    int32_t defence = 0;
    int32_t attack_time = 0;

    // Fires when player hits movement controlling buttons. Probably W/A/S/D.
    // Return true when moved successfully.
    // TODO: When move fired, if is is possible - change the hero position.
    bool move(Direction& direction);
    Entity() = default;
    Entity(const Entity& entity);
};