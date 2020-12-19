#pragma once


#include "entity.hpp"
#include <string>

struct Hero : Entity
{
    std::string nick;

    ProfessionType profession_type = ProfessionType::NONE;
    std::string profession_type_name;

    Hero() = default;

    /// Initialize hero stats.
    void init_random_stats(ProfessionType &profession_type_);

    /// Increase lvl and update hero stats.
    void increase_lvl();
};
