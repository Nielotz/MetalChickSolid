#pragma once
#define _HAS_STD_BYTE 0
#include <iostream>
#include "profession.cpp"

struct Entity
{
    int32_t lvl = 1;
    int32_t exp = 0;
    int32_t hp = 50;
    int32_t hit = 10;
    uint8_t fight_distance = 0;
    long double attack_time = 100;
    double block_chance = 1;
    double dodge_chance = 1;
    uint8_t critic_hit_chance = 1;
    ProfessionType profession_type;

};