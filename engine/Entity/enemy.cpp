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

    typedef std::pair<uint8_t, Item> chance_item;
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
    typedef std::pair<uint8_t, Item> chance_item;
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

Enemy::Enemy()
{
}

Enemy::Enemy(const Enemy&)
{
}
