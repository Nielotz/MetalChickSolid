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

    typedef std::pair<uint8_t, Item> chance_item;
    loot.push_back(chance_item{ 50, BasicSword() });
    loot.push_back(chance_item{ 20, FancySword() });
}

Fox::Fox()
{
    name = "Fox";
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
    stamina = 4;
    critical = 3;
    strength = 5;
    agility = 3;
    attack_time = 37;
    defence = 5;
    critical_power = 2;
    block = 2;
}

void Dragon::update_stats(uint16_t lvl)
{
}



Enemy::Enemy()
{
}

Enemy::Enemy(Position position)
{
    this->position = position;
}

Enemy::Enemy(const Enemy& enemy)
{
    position.x = enemy.position.x;
    position.y = enemy.position.y;
    profession_type = enemy.profession_type;
    lvl = enemy.lvl;
    exp = enemy.exp;
    hp = enemy.hp;
    hp_max = enemy.hp_max;
    mana = enemy.mana;
    stamina = enemy.stamina;
    strength = enemy.strength;
    agility = enemy.agility;
    intelect = enemy.intelect;
    critical = enemy.critical;
    critical_power = enemy.critical_power;
    block = enemy.block;
    defence = enemy.defence;
    attack_time = enemy.attack_time;
}

void Bear::update_stats(uint16_t lvl)
{
    double base = lvl + lvl * .025;
    hp_max = int(base * 6);
    stamina = int(base * 3);
    critical = int(base * 2);
    strength = int(base * 3);
    attack_time = int(base * 35);
    defence = int(base * 2);
}

void Deer::update_stats(uint16_t lvl)
{
    double base = lvl + lvl * .025;
    hp_max = int(base * 5);
    stamina = int(base * 3);
    critical = int(base * 1);
    strength = int(base * 2);
    attack_time = int(base * 4);
    defence = int(base * 1);
}

void Troll::update_stats(uint16_t lvl)
{
    double base = lvl + lvl * .025;
    hp_max = int(base * 8);
    stamina = int(base * 4);
    critical = int(base * 4);
    strength = int(base * 4);
    attack_time = int(base * 8);
    defence = int(base * 5);
}

void Goblin::update_stats(uint16_t lvl)
{
    double base = lvl + lvl * .025;
    hp_max = int(base * 7);
    stamina = int(base * 4);
    critical = int(base * 2);
    strength = int(base * 3);
    attack_time = int(base * 7);
    defence = int(base * 3);
}

void Fox::update_stats(uint16_t lvl)
{
    double base = lvl + lvl * .025;
    hp_max = int(base * 9);
    stamina = int(base * 5);
    critical = int(base * 3);
    strength = int(base * 6);
    attack_time = int(base * 9);
    defence = int(base * 4);
}