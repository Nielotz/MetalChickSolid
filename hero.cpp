#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <random>
#include <conio.h>
#include <fstream>

#include "profession.cpp"
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

        modifier = distribution(generator) / 100.;
        hit *= modifier;

        modifier = distribution(generator) / 100.;
        fight_distance *= modifier;

        modifier = distribution(generator) / 100.;
        block_chance *= modifier;

        modifier = distribution(generator) / 100.;
        dodge_chance *= modifier;

        modifier = distribution(generator) / 100.;
        critic_hit_chance *= modifier;

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
            fight_distance = 2;
        }
        else
        {
            block_chance = 0;
            dodge_chance = 0;
            critic_hit_chance += 5;
            fight_distance = 1;
        }
	}

public:
    bool is_man;
    string nick;
    ProfessionType profession_type;
    string profession_type_name;

    void save(ofstream &file)
    {
        file << "nick: " << nick << "\n"
        << "is_man: " << is_man << "\n"
        << "profession_type: " << profession_type << "\n"
        << "lvl: " << lvl << "\n"
        << "exp: " << exp << "\n"
        << "hp: " << hp << "\n"
        << "hit: " << hit << "\n"
        << "fight_distance: " << fight_distance << "\n"
        << "block_chance: " << block_chance << "\n"
        << "dodge_chance: " << dodge_chance << "\n"
        << "critic_hit_chance: " << critic_hit_chance << "\n";
    }
    void print_stats_card()
    {
        if (profession_type == WARRIOR)
            profession_type_name = "Wojownik";
        else if(profession_type == HUNTER)
            profession_type_name = "Łowca";
        else
            profession_type_name = "Mag";

        cout << "\n"
        << "Hero(" << nick << " " << char('m'*is_man + 'k'*(!is_man)) << " lvl: "<< lvl << " " << profession_type_name << ") stats card: \n"
        << "   HP: " << hp << " \n"
        << "   Uderzenie: " << hit << " \n"
        << "   Odległość walki: " << fight_distance << " \n"
        << "   Szansa na blok: " << block_chance << " %\n"
        << "   Szansa na unik: " << dodge_chance << " %\n"
        << "   Szansa na cios krytyczny: " << critic_hit_chance << " %\n\n";
    }

    Hero() = default;

	Hero(string nick, bool is_man, const ProfessionType profession_type, bool auto_generate_stats)
	: nick(std::move(nick)), is_man(is_man), profession_type(profession_type)
	{


        if (auto_generate_stats)
        {
            init_stats(profession_type);
            print_stats_card();
        }
	};


};