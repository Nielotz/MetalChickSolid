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
    std::string name = "Deer";
    uint32_t hp_max = 5;
    uint32_t stamina = 3;
    uint32_t agility = 2;
    uint32_t strength = 1;
    uint32_t attack_time = 1;
    typedef std::pair<uint8_t, Item> chance_item;
    std::vector<chance_item> loot = {
      chance_item{50, Meat()},
      chance_item{20, FancyMeat()}
    };
};

struct Bear : Enemy
{
    Bear();
};

struct Goblin : Enemy
{
    std::string name = "Goblin";
    uint32_t hp_max = 15;
    uint32_t stamina = 2;
    uint32_t critical = 1;
    uint32_t strength = 1;
    uint32_t agility = 2;
    uint32_t attack_time = 2;
    int32_t defence = 3;
    typedef std::pair<uint8_t, Item> chance_item;
    std::vector<chance_item> loot = {
      chance_item{20, BasicArmor()},
      chance_item{40, FancyArmor()}
    };
};

struct Troll : Enemy
{
    std::string name = "Troll";
    uint32_t hp_max = 20;
    uint32_t stamina = 2;
    uint32_t critical = 2;
    uint32_t strength = 3;
    uint32_t agility = 1;
    uint32_t attack_time = 3;
    int32_t defence = 2;
    typedef std::pair<uint8_t, Item> chance_item;
    std::vector<chance_item> loot = {
      chance_item{20, BasicSword()},
      chance_item{40, FancySword()}
    };
};

struct Fox : Enemy
{
    std::string name = "Fox";
    uint32_t hp_max = 25;
    uint32_t stamina = 3;
    uint32_t strength = 1;
    uint32_t agility = 5;
    uint32_t attack_time = 4;
    int32_t defence = 4;
    typedef std::pair<uint8_t, Item> chance_item;
    std::vector<chance_item> loot = {
      chance_item{20, BasicShield()},
      chance_item{40, FancyShield()}
    };
};

struct Dragon : Enemy
{
    std::string name = "Dragon";
    uint32_t hp_max = 35;
    uint32_t stamina = 3;
    uint32_t critical = 3;
    uint32_t strength = 5;
    uint32_t agility = 3;
    uint32_t attack_time = 5;
    int32_t defence = 5;
    int32_t critical_power = 2;
    int32_t block = 2;
};