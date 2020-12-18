#pragma once

#include <string>

#include "profession.hpp"

enum class ItemType {
    NONE = 0,
    //HELMET = 1,
    //RING = 2,
    //NECKLACE = 3,
    //GLOVES = 4,
    WEAPON = 5,
    ARMOR = 6,

    // Support.
    SHIELD = 10,
    //ARROWS = 11,
    //ORB = 12,

    // Consumables.
    //CONSUMABLE = 20
};

struct Item
{
    std::string name = "Not set";
    ItemType item_type = ItemType::NONE;
    ProfessionType profession_required = ProfessionType::NONE;
    uint32_t lvl_required = 0;
};
