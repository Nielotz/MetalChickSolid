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
    int32_t stamina = 0;
    int32_t strength = 0;
    int32_t agility = 0;
    int32_t defence = 0;
    int32_t attack_time = 0;
    std::vector<std::pair<uint8_t, Item>> loot;
    std::string name;

    void update_stats(uint16_t lvl);

    // Have to be shhh.
    Enemy();
    Enemy(Position position);
    Enemy(const Enemy&);
};

struct Deer : Enemy
{
    Deer();
    void update_stats(uint16_t lvl);
};

struct Bear : Enemy
{
    Bear();
    void update_stats(uint16_t lvl);
};

struct Goblin : Enemy
{
    Goblin();
    void update_stats(uint16_t lvl);
};

struct Troll : Enemy
{
    Troll();
    void update_stats(uint16_t lvl);
};

struct Fox : Enemy
{
    Fox();
    void update_stats(uint16_t lvl);
};

struct Dragon : Enemy
{
    Dragon();
    void update_stats(uint16_t lvl);
};