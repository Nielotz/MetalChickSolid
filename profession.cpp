#pragma once

#include <iostream>

using namespace std;


enum ProfessionType
{
    WARRIOR, HUNTER, MAGICIAN
};

class Profession
{
public:
    int64_t max_base_hp = 100;
    int64_t max_base_hit = 50;
    uint8_t fight_distance = 0;
};

class Warrior : Profession
{
public:
    int64_t max_base_hp = 100;
    int64_t max_base_hit = 50;
    uint8_t fight_distance = 0;

    // From 0 to 100 [%].
    uint8_t block_chance = 0;
};

class Hunter : Profession
{
public:
    int64_t max_base_hp = 80;
    int64_t max_base_hit = 10;
    uint8_t fight_distance = 2;

    // From 0 to 100 [%].
    uint8_t dodge_chance = 1;
};

class Magician : Profession
{
public:
    int64_t max_base_hp = 60;
    int64_t max_base_hit = 10;
    uint8_t fight_distance = 1;

    // From 0 to 100 [%].
    uint8_t critic_hit_chance = 2;
};