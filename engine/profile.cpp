#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include "../headers/profession.hpp"
#include "../headers/hero.hpp"
#include "../headers/profile.hpp"


/// Not done yet.
void Profile::load()
{
    if (path.empty())
        throw std::runtime_error("Before use Profile::load profile path need to be set!");

    hero = Hero();

    std::ifstream input(path, std::ios::out);
    std::string keyword;

    while (input >> keyword)
    {
        if (keyword == "nick:")
        {
            char dummy_char;
            input.read(&dummy_char, 1);
            getline(input, hero.nick);
            if (dummy_char != ' ')
                hero.nick = ' ' + hero.nick;
        } else if (keyword == "profession_required:")
        {
            uint16_t type;
            input >> type;
            hero.profession_type = ProfessionType(type);
        } else if (keyword == "lvl:")
            input >> hero.lvl;
        else if (keyword == "exp:")
            input >> hero.exp;
        else if (keyword == "hp:")
            input >> hero.hp;
        else if (keyword == "hit:")
            input >> hero.hit;
        else
        {
            std::cout << "Niepoprawny parametr: '" << keyword << "', pomijam." << std::endl;
        }

    }
}

void Profile::create_new()
{

}

void Profile::save()
{

}
