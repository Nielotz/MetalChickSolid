#include "../headers/profile.hpp"
#include "../headers/consts.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>


//All keywords that appear in the file:
//nick, profession, lvl, exp, hp, current_map, poz_x, poz_y, eq_item_1...20, thread_1...10, enemy_status_1...10,


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
        else if (keyword == "profession:")
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
        else if (keyword == "poz_x:")
            input >> hero.position.x;
        else if (keyword == "poz_y:")
            input >> hero.position.y;
        else if (keyword == "eq_item:")
        {
            int16_t i;
            uint16_t type;
            input >> i;
            input >> type;
            hero.inventory[i].item_type = ItemType(type);
        }
        else if (keyword == "thread:")
        {
            int16_t i;
            int8_t type;
            input >> i;
            input >> type;
            hero.thread_status[i] = type;
        }
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
    //Here will start graphic hero creator
    new_file << "nick: Dumb\nprofession: 1\nlvl: 1\nexp: 0\nhp: 100\npoz_x: 4\npoz_y: 10\n";
    for (int i = 0; i < 20; i++) {
        new_file << "eq_item: " << i << " 0\n";
    }
    for (int i = 0; i < 10; i++) {
        new_file << "thread: " << i << " 0\n";
    }
    new_file.close();
}

void Profile::save()
{
    std::ofstream save_file;
    save_file.open(path);
    save_file << "nick: " << hero.name << "\n";
    save_file << "profession: " << uint16_t(hero.profession_type) << "\n";
    save_file << "lvl: " << hero.lvl << "\n";
    save_file << "exp: " << hero.exp << "\n";
    save_file << "hp: " << hero.hp << "\n";
    //save_file << "current_map: " << PATH::MAP::TEXTURES::START << "\n";
    save_file << "poz_x: " << hero.position.x << "\n";
    save_file << "poz_y: " << hero.position.y << "\n";
    for (int i = 0; i < 20; i++) {
        save_file << "eq_item: " << i << " " << uint16_t(hero.inventory[i].item_type) << "\n";
    }
    for (int i = 0; i < 10; i++) {
        save_file << "thread: " << i << " " << int8_t(hero.thread_status[i]) << "\n";
    }
    /*
    for (int i = 0; i < 10; i++) {
        save_file << "enemy_status: " << i << " " <<  << "\n";
    }*/
    save_file.close();
    std::cout << "Saved.\n";
}
