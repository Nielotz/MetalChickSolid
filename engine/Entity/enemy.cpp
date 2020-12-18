#pragma once
#define _HAS_STD_BYTE 0
#include <random>
#include "entity.cpp"
#include "hero.cpp"

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

struct Beaver : Enemy
{
    Beaver(int16_t difficulty, Hero *hero)
    {
        uint16_t min_difficulty;
        uint16_t max_difficulty;
        if (difficulty < -100)
            min_difficulty = -100;
        if (difficulty > 100)
            max_difficulty = 100;

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(difficulty - 25, difficulty + 25);

        hp = hero->hp * (1. + distribution(generator) / 100.);
        hit = hero->hit * (1. + distribution(generator) / 100.);
        fight_distance = hero->fight_distance * (1. + distribution(generator) / 100.);
        block_chance = hero->block_chance * (1. + distribution(generator) / 100.);
        dodge_chance = hero->dodge_chance * (1. + distribution(generator) / 100.);
        attack_time = hero->attack_time * (1. + distribution(generator) / 100.);
    }
};