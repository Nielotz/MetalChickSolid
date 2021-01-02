#pragma once


#include "entity.hpp"
#include <string>

struct Hero : Entity
{
    std::string nick;

    ProfessionType profession_type = ProfessionType::NONE;
    std::string profession_type_name;

    Hero() = default;

    /// Increase lvl and update hero stats.
    void increase_lvl();
};
