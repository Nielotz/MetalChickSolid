#pragma once

#include <string>

#include "profession.hpp"

enum class ItemType
{
    NONE = 0,
    CONSUMABLE = 1, 
    ALTER_STATS = 2 
};

struct Item
{
    std::string name = "Not set";
    ItemType item_type = ItemType::NONE;
    ProfessionType profession_required = ProfessionType::WARRIOR;
    uint32_t lvl_required = 0;
    uint32_t hp = 0;

};

struct MagicSword : Item
{
    std::string name = "Not set";
    ItemType item_type = ItemType::NONE;
    ProfessionType profession_required = ProfessionType::WARRIOR;
};