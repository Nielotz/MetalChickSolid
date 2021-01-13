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
    int32_t hp_bonus = 0;
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
};

struct Consumable : Item
{
    ItemType item_type = ItemType::CONSUMABLE;
};

struct Alter_stats : Item
{
    ItemType item_type = ItemType::ALTER_STATS;
};

struct BasicSword : Alter_stats
{
    std::string name = "Not set";
    ProfessionType profession_required = ProfessionType::WARRIOR;
    uint32_t strength = 1;
};

struct BasicShield : Alter_stats
{
    std::string name = "Not set";
    ProfessionType profession_required = ProfessionType::WARRIOR;
    uint32_t block = 1;
};

struct BasicArmor : Alter_stats
{
    std::string name = "Not set";
    ProfessionType profession_required = ProfessionType::WARRIOR;
    uint32_t block = 1;
    uint32_t defence = 1;
};

struct FancyShield : Alter_stats
{
    std::string name = "Not set";
    ProfessionType profession_required = ProfessionType::WARRIOR;
    uint32_t block = 3;
};

struct FancyArmor : Alter_stats
{
    std::string name = "Not set";
    ProfessionType profession_required = ProfessionType::WARRIOR;
    uint32_t block = 3;
    uint32_t defence = 3;
};

struct MagicSword : Alter_stats
{
    std::string name = "Not set";
    ProfessionType profession_required = ProfessionType::WARRIOR;
    uint32_t strength = 3;
    uint32_t critical = 2;
};

struct FancyMeat : Consumable
{
    std::string name = "Not set";
    ProfessionType profession_required = ProfessionType::WARRIOR;
    uint32_t hp_bonus = 5; //do sprawdzenia
    uint32_t stamina = 5;
};

struct Meat : Consumable
{
    std::string name = "Not set";
    ProfessionType profession_required = ProfessionType::WARRIOR;
    uint32_t hp_bonus = 2; //do sprawdzenia
    uint32_t stamina = 2;
};
