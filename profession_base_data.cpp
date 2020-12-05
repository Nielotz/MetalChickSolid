#pragma once

#include <iostream>

using namespace std;


enum ProfessionType
{
    WARRIOR, HUNTER, MAGICIAN
};

struct ProfessionBaseData
{
    static int64_t max_base_hp;
    static int64_t max_base_hit;
    static uint8_t fight_distance;
    static uint8_t block_chance;
    static uint8_t dodge_chance;
    static uint8_t critic_hit_chance;
};

struct WarriorBaseData : ProfessionBaseData
{
    WarriorBaseData() {
        max_base_hit = 50;
        cout << ProfessionBaseData::max_base_hp << endl;
        max_base_hp = 100;
        fight_distance = 0;

        // From 0 to 100 [%].
        block_chance = 1;
    }
};


struct HunterBaseData : ProfessionBaseData
{
    HunterBaseData()
    {
        max_base_hp = 80;
        max_base_hit = 10;
        fight_distance = 2;

        // From 0 to 100 [%].
        dodge_chance = 1;
    }

};

struct MagicianBaseData : ProfessionBaseData
{
    MagicianBaseData() {
        max_base_hp = 60;
        max_base_hit = 10;
        fight_distance = 1;

        // From 0 to 100 [%].
        critic_hit_chance = 2;
    }
};