#pragma once
#define _HAS_STD_BYTE 0
#include "hero.cpp"

class Arena
{
    Arena() = default;
    // Returns whether hero won.
    bool fight(Hero& hero, Entity& enemy)
    {
        // Whose number is bigger - attacks.
        //uint16_t hero_attack_time = hero; //
        uint16_t enemy_attack_time;

        for (uint8_t turn_number = 0; turn_number < 100; turn_number++)
        {
            //if ()
        }
    }
};