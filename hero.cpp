#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <random>
#include <conio.h>

#include "profession_base_data.cpp"
#include "entity.cpp"

#pragma once

using namespace std;


struct Hero : Entity
{
private:
	void init_stats(ProfessionType profession_type_)
	{
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(50, 150);

        double modifier = distribution(generator) / 100.;
        hp *= modifier;
        cout << modifier << endl;

        modifier = distribution(generator) / 100.;
        hit *= modifier;
        cout << modifier << endl;

        modifier = distribution(generator) / 100.;
        fight_distance *= modifier;
        cout << modifier << endl;

        modifier = distribution(generator) / 100.;
        block_chance *= modifier;
        cout << modifier << endl;

        modifier = distribution(generator) / 100.;
        dodge_chance *= modifier;
        cout << modifier << endl;

        modifier = distribution(generator) / 100.;
        critic_hit_chance *= modifier;
        cout << modifier << endl;

        if (profession_type_ == WARRIOR)
        {
            hp *= 1.25;
            hit *= 1.25;
            dodge_chance = 0;
        }
        else if (profession_type_ == HUNTER)
        {
            hp *= 1.10;
            hit *= 0.8;
            block_chance = 0;
        }
        else
        {
            block_chance = 0;
            dodge_chance = 0;
            critic_hit_chance += 5;
        }
	}

public:
    const bool is_man;
    const string nick;
    const ProfessionType profession_type;

    void print_stats_card()
    {
        cout << "\n"
                "Hero stats card: \n"
                "   HP: " << hp << " \n" <<
                "   Uderzenie: " << hit << " \n" <<
                "   Odległość walki: " << fight_distance << " \n" <<
                "   Szansa na blok: " << block_chance << " %\n" <<
                "   Szansa na unik: " << dodge_chance << " %\n" <<
                "   Szansa na cios krytyczny: " << critic_hit_chance << " %\n\n";
    }

	Hero(string nick, bool is_man, const ProfessionType profession_type, bool auto_generate_stats)
	:nick(std::move(nick)), is_man(is_man), profession_type(profession_type)
	{
        if (auto_generate_stats)
        {
            init_stats(profession_type);
            print_stats_card();

        }
	};

};