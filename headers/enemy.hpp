#pragma once

#include "entity.hpp"
#include "hero.hpp"

#include <cstdint>
#include <vector>


struct Enemy : Entity
{
    ///Status (dead, alive)
    int8_t status;
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
    std::vector<std::pair<uint8_t, Item>> loot;
    std::string name;


    // Have to be shhh.
    Enemy();
    Enemy(const Enemy&);
};

struct Deer : Enemy
{
    Deer();
};

struct Bear : Enemy
{
    Bear();
};

struct Goblin : Enemy
{
    Goblin();
};

struct Troll : Enemy
{
    Troll();
};

struct Fox : Enemy
{
    Fox();
};

struct Dragon : Enemy
{
    Dragon();
};