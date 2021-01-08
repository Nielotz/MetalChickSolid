#include "../headers/profile.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>


//All keywords that appear in the file:
//nick, profession_required, lvl, exp, hp


/// Not done yet.
void Profile::load()
{
    if (path.empty())
        throw std::runtime_error("Before use Profile::load profile path need to be set!");

    //If file exist?
    std::ifstream file_save(path.c_str());
    if (file_save.good() == 0)
    {
        std::cout << "Profile file doesn't exist, creating new one...\n";
        create_new();
    }
    file_save.close();

    hero = Hero();

    std::ifstream input(path, std::ios::out);
    std::string keyword;

    while (input >> keyword)
    {
        if (keyword == "nick:")
        {
            char dummy_char;
            input.read(&dummy_char, 1);
            getline(input, hero.name);
            if (dummy_char != ' ')
                hero.name = ' ' + hero.name;
        }
        else if (keyword == "profession_required:")
        {
            uint16_t type;
            input >> type;
            hero.profession_type = ProfessionType(type);
        }
        else if (keyword == "lvl:")
        {
            input >> hero.lvl;
            hero.update_attributes();
        }
        else if (keyword == "exp:")
            input >> hero.exp;
        else if (keyword == "hp:")
            input >> hero.hp;
        else
        {
            std::cout << "Niepoprawny parametr: '" << keyword << "', pomijam." << std::endl;
        }

    }
}

void Profile::create_new()
{
    std::ofstream new_file(path);
    std::cout << "Creating dumb profile...\n";
    new_file << "nick: Dumb\nprofession_required: 1\nlvl: 1\nexp: 0\nhp: 100\n";
    new_file.close();
}

void Profile::save()
{

}
