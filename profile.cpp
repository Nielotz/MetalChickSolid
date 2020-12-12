#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <conio.h>

#include "profession.cpp"
#include "hero.cpp"

struct Profile
{
    Hero *hero = nullptr;
    const string path;
    void create_new()
    {
        string nick;
        cout << "Tworzenie nowego profilu.\n"
                "Wprowadź nick: ";
        nick = "xyz";
        std::getline(std::cin, nick);
        string answer;

        bool is_man;
        bool should_while_loop_keep_looping_true_means_not_selected_gender = true;
        while (should_while_loop_keep_looping_true_means_not_selected_gender)
        {
            cout << "Wybierz płeć (m / k): ";
            should_while_loop_keep_looping_true_means_not_selected_gender = false;
            answer = "m";
            cin >> answer;
            if (answer == "m" || answer == "M" )
                is_man = true;
            else if (answer == "k" || answer == "K" )
                is_man = false;
            else
                should_while_loop_keep_looping_true_means_not_selected_gender = true;
        }

        ProfessionType profession_type;

        bool should_while_loop_keep_looping_true_means_not_selected_profession = true;
        while (should_while_loop_keep_looping_true_means_not_selected_profession)
        {
            cout << "Witaj " + nick << "!\n"
            << "Wybierz profesję: \n"
               "    1. Łowca (Atak z dystansu(2), trucizna, unik)\n"
               "    2. Wojownik (Silny atak, blok tarczą, wytrzymały)\n"
               "    3. Mag (Atak z dystansu(1), leczenie ran, ataków nie da się uniknąć / zablokować):\n";
            should_while_loop_keep_looping_true_means_not_selected_profession = false;
            answer = "3";
            cin >> answer;
            if (answer == "1")
                    profession_type = HUNTER;
            else if (answer == "2")
                    profession_type = WARRIOR;
            else if (answer == "3")
                profession_type = MAGICIAN;
            else
                should_while_loop_keep_looping_true_means_not_selected_profession = true;
        }

        hero = new Hero(nick, is_man, profession_type, true);
    }

    explicit Profile(const string& filename)
    : path(filename)
    {
        if (!filesystem::exists(filename))
            create_new();
        else
            load(filename);

    }

    ~Profile()
    {
        save();
        delete hero;
    }


    void load(const string &filename)
    {
        if (hero == nullptr)
            hero = new Hero();

        ifstream input(filename, ios::out);
        string keyword;

        while (input >> keyword)
        {
            if (keyword == "nick:")
            {
                char dummy_char;
                input.read(&dummy_char, 1 );
                getline(input, hero->nick);
                if (dummy_char != ' ')
                    hero->nick = ' ' + hero->nick;
            }
            else if (keyword == "profession_type:")
            {
                uint16_t type;
                input >> type;
                hero->profession_type = ProfessionType(type);
            }
            else if (keyword == "is_man:")
                input >> hero->is_man;
            else if (keyword == "lvl:")
                input >> hero->lvl;
            else if (keyword == "exp:")
                input >> hero->exp;
            else if (keyword == "hp:")
                input >> hero->hp;
            else if (keyword == "attack_time:")
                input >> hero->attack_time;
            else if (keyword == "hit:")
                input >> hero->hit;
            else if (keyword == "fight_distance:")
                input >> hero->fight_distance;
            else if (keyword == "block_chance:")
                input >> hero->block_chance;
            else if (keyword == "dodge_chance:")
                input >> hero->dodge_chance;
            else if (keyword == "critic_hit_chance:")
                input >> hero->critic_hit_chance;
            else
            {
                cout << "Niepoprawny parametr: '" << keyword << "', pomijam." << endl;
            }

        }
    }

    void save() const
    {
        ofstream output(path, ios::in | ios::trunc);

        hero->save(output);

        output.close();
    }
};
