#pragma once

#include <string>
#include <vector>

#include "profession.cpp"

enum ItemType {
    HELMET = 0,
    RING = 1,
    NECKLACE = 2,
    GLOVES = 3,
    WEAPON = 4,
    ARMOR = 5,

    // Support.
    SHIELD = 10,
    ARROWS = 11,
    ORB = 12,

    // Consumables.
    DRUG = 20
};

struct Item
{
    std::string name;
    uint64_t lvl_required = 0;
    ProfessionType profession_type = ProfessionType::ANY;
};

struct Weapon : Item
{
    const ItemType item_type = ItemType::WEAPON;
    uint64_t dmg{};

    Weapon(string&& name, uint64_t dmg, ProfessionType profession_type)
    {
        this->name = name;
        this->dmg = dmg;
        this->profession_type = profession_type;
    }
};

struct Items
{
    std::vector<Weapon> weapons;
};
