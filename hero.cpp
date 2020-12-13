#pragma once
#define _HAS_STD_BYTE 0
#include <iostream>
#include <string>
#include <utility>
#include <random>
#include <fstream>

#include "profession.cpp"
#include "entity.cpp"
#include "graphic.cpp"

#pragma once


struct Hero : Entity
{
private:
	void init_stats(ProfessionType profession_type_)
	{
        profession_type = profession_type_;

        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(50, 150);

        hp *= distribution(generator) / 100.;
        hit *= distribution(generator) / 100.;
        fight_distance *= distribution(generator) / 100.;
        block_chance *= distribution(generator) / 100.;
        dodge_chance *= distribution(generator) / 100.;
        attack_time *= distribution(generator) / 100.;


        if (profession_type_ == WARRIOR)
        {
            hp_modifier = 1.25;
            hit_modifier = 1.25;

            attack_time *= 1.4;
        }
        else if (profession_type_ == HUNTER)
        {
            hp_modifier  = 1.10;
            hit_modifier  = 0.8;

            block_chance = 0;
            fight_distance = 2;
            attack_time *= 0.8;
        }
        else // MAGICIAN
        {
            hp_modifier = 0.9;
            hit_modifier = 1.1;

            block_chance = 0;
            dodge_chance = 0;
            critic_hit_chance += 5;
            fight_distance = 1;
            attack_time *= 1.1;
        }
        hp *= hp_modifier;
        hit *= hit_modifier;
	}

public:
    bool is_man = true;
    std::string nick;
    ProfessionType profession_type = ProfessionType::ANY;
    std::string profession_type_name;
    float hp_modifier;
    float hit_modifier;

    void save(ofstream &file)
    {
        file << "nick: " << nick << "\n"
        << "is_man: " << to_string(is_man) << "\n"
        << "profession_type: " << to_string(profession_type) << "\n"
        << "lvl: " << to_string(lvl) << "\n"
        << "exp: " << to_string(exp) << "\n"
        << "hp: " << to_string(hp) << "\n"
        << "hit: " << to_string(hit) << "\n"
        << "fight_distance: " << to_string(fight_distance) << "\n"
        << "attack_time: " << to_string(attack_time) << "\n"
        << "block_chance: " << to_string(block_chance) << "\n"
        << "dodge_chance: " << to_string(dodge_chance) << "\n"
        << "critic_hit_chance: " << to_string(critic_hit_chance) << flush;
    }

    void print_stats_card(Graphic& graphic)
    {
        if (profession_type == WARRIOR)
            profession_type_name = "Wojownik";
        else if(profession_type == HUNTER)
            profession_type_name = "Łowca";
        else
            profession_type_name = "Mag";

        graphic.print_with_timeout_between_chars(string("\n")
        + "Hero " + nick + " (" + char('m'*is_man + 'k'*(!is_man)) + " lvl: " + to_string(lvl) + " " + profession_type_name + ") statystyki: \n"
        + string("   HP: ") + to_string(hp) + " \n"
        + "   Doświadczenie: " + to_string(exp) + " \n"
        + "   Uderzenie: " + to_string(hit) + " \n"
        + "   Odległość walki: " + to_string(fight_distance) + " \n"
        + "   Czas ataku: " + to_string(attack_time) + " \n"
        + "   Szansa na blok: " + to_string(block_chance) + " %\n"
        + "   Szansa na unik: " + to_string(dodge_chance) + " %\n"
        + "   Szansa na cios krytyczny: " + to_string(critic_hit_chance) + " %\n\n", 10 );
    }

    void increase_lvl()
    {
        lvl += 1;

        if (profession_type == ProfessionType::MAGICIAN)
        {
            hp += lvl * 5 * 0.8;
        }
        cout << "Awansowałeś poziom!\n"
                "Twój nowy poziom: " << lvl << endl;

    }

    Hero() = default;

	Hero(string nick, bool is_man, const ProfessionType profession_type, bool auto_generate_stats)
	: nick(std::move(nick)), is_man(is_man), profession_type(profession_type)
	{
        if (auto_generate_stats)
        {
            init_stats(profession_type);
        }
	};


};