#include <iostream>

struct Entity
{
    int64_t hp = 50;
    int64_t hit = 10;
    uint8_t fight_distance = 0;
    uint8_t block_chance = 1;
    uint8_t dodge_chance = 1;
    uint8_t critic_hit_chance = 1;
};