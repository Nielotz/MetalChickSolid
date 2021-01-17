#include "../../headers/enemy.hpp"

Bear::Bear()
{
    name = "Bear";
    hp_max = 10;
    stamina = 3;
    critical = 2;
    strength = 1;
    attack_time = 1;
    defence = 2;

    typedef std::pair <uint8_t, Item> chance_item;
    loot.push_back(chance_item{ 70, Meat() });
    loot.push_back(chance_item{ 40, FancyMeat() });
}

Deer::Deer()
{
    name = "Deer";
    hp_max = 5;
    stamina = 3;
    agility = 2;
    strength = 1;
    attack_time = 1;

    update_stats(lvl);
    {
        uint32_t base = lvl + lvl * .025;
        hp_max = base * 5;
        stamina = base * 3;
        critical = base * 2;
        strength = base * 3;
        attack_time = base * 5;
        defence = base;
    }

    typedef std::pair<uint8_t, Item> chance_item;
    loot.push_back(chance_item{ 50, Meat() });
    loot.push_back(chance_item{ 20, FancyMeat() });
}

Goblin::Goblin()
{
    name = "Goblin";
    hp_max = 15;
    stamina = 2;
    critical = 1;
    strength = 1;
    agility = 2;
    attack_time = 2;
    defence = 3;

    update_stats(lvl);
    {
        uint32_t base = lvl + lvl * .025;
        hp_max = base * 6;
        stamina = base * 3;
        critical = base * 2;
        strength = base * 3;
        attack_time = base * 5;
        defence = base * 2;
    }

    typedef std::pair<uint8_t, Item> chance_item;
    loot.push_back(chance_item{ 50, BasicArmor() });
    loot.push_back(chance_item{ 20, FancyArmor() });
}

Troll::Troll()
{
    name = "Troll";
    hp_max = 20;
    stamina = 2;
    critical = 2;
    strength = 3;
    agility = 1;
    attack_time = 3;
    defence = 2;

    update_stats(lvl);
    {
        uint32_t base = lvl + lvl * .025;
        hp_max = base * 6;
        stamina = base * 3;
        critical = base * 2;
        strength = base * 3;
        attack_time = base * 5;
        defence = base * 2;
    }

    typedef std::pair<uint8_t, Item> chance_item;
    loot.push_back(chance_item{ 50, BasicSword() });
    loot.push_back(chance_item{ 20, FancySword() });
}

Fox::Fox()
{
    name = "Fox";
    hp_max = 25;
    stamina = 3;
    strength = 1;
    agility = 5;
    attack_time = 4;
    defence = 4;

    update_stats(lvl);
    {
        uint32_t base = lvl + lvl * .025;
        hp_max = base * 6;
        stamina = base * 3;
        critical = base * 2;
        strength = base * 3;
        attack_time = base * 5;
        defence = base * 2;
    }

    typedef std::pair <uint8_t, Item> chance_item;
    loot.push_back(chance_item{ 50, BasicShield() });
    loot.push_back(chance_item{ 20, FancyShield() });
}

Dragon::Dragon()
{
    name = "Dragon";
    hp_max = 35;
    stamina = 3;
    critical = 3;
    strength = 5;
    agility = 3;
    attack_time = 5;
    defence = 5;
    critical_power = 2;
    block = 2;
}

void Enemy::update_stats(uint16_t lvl)
{
}

Enemy::Enemy()
{
}

Enemy::Enemy(const Enemy&)
{
}

void Bear::update_stats(uint16_t lvl)
{
    uint32_t base = lvl + lvl * .025;
    hp_max = base * 6;
    stamina = base * 3;
    critical = base * 2;
    strength = base * 3;
    attack_time = base * 5;
    defence = base * 2;
}

void Deer::update_stats(uint16_t lvl)
{
    uint32_t base = lvl + lvl * .025;
    hp_max = base * 5;
    stamina = base * 3;
    critical = base * 1;
    strength = base * 2;
    attack_time = base * 4;
    defence = base * 1;
}

void Troll::update_stats(uint16_t lvl)
{
    uint32_t base = lvl + lvl * .025;
    hp_max = base * 8;
    stamina = base * 4;
    critical = base * 4;
    strength = base * 4;
    attack_time = base * 8;
    defence = base * 5;
}

void Goblin::update_stats(uint16_t lvl)
{
    uint32_t base = lvl + lvl * .025;
    hp_max = base * 7;
    stamina = base * 4;
    critical = base * 2;
    strength = base * 3;
    attack_time = base * 7;
    defence = base * 3;
}

void Fox::update_stats(uint16_t lvl)
{
    uint32_t base = lvl + lvl * .025;
    hp_max = base * 9;
    stamina = base * 5;
    critical = base * 3;
    strength = base * 6;
    attack_time = base * 9;
    defence = base * 4;
}