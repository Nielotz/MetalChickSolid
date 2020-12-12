#pragma once
#define _HAS_STD_BYTE 0
#include <iostream>
#include "profession.cpp"

struct Entity
{
    int64_t lvl = 1;
    int64_t exp = 0;
    int64_t hp = 50;
    int64_t hit = 10;
    uint16_t fight_distance = 0;
    long double attack_time = 100;
    double block_chance = 1;
    double dodge_chance = 1;
    double critic_hit_chance = 1;
    ProfessionType profession_type;

};