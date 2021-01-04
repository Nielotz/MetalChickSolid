#pragma once


#include "entity.hpp"
#include "item.hpp"
#include <string>

struct Hero : Entity
{
    ProfessionType profession_type = ProfessionType::NONE;
    std::string profession_type_name;

    //Inventory
    Item inventory[20];

    Hero() = default;

    /// Increase lvl and update hero stats.
    void increase_lvl();

    //Update Level-dependent attributes
    void update_attributes();
};
