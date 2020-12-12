#pragma once

#include "entity.cpp"
#include "entity.cpp"

struct Enemy : Entity
{
    Enemy()
    {
        lvl = 1;
        hp = 0;
        hit = 0;
        fight_distance = 0;
        attack_time = 0;
        block_chance = 0;
        dodge_chance = 0;
        critic_hit_chance = 0;
        profession_type = ProfessionType::ANY;
    }
};
