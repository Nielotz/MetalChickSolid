#pragma once
#include <iostream>
#include <filesystem>
#include <string>
#include <conio.h>

#include "profession_base_data.cpp"
#include "hero.cpp"

using namespace std;

struct Profile
{
    Hero *hero = nullptr;
    void create_new()
    {
        string nick = "test";
        cout << "Tworzenie nowego profilu.\n"
                "Wprowadź nick: ";
        // std::getline(std::cin, nick);

        bool is_man;
        bool should_while_loop_keep_looping_true_means_not_selected_gender = true;
        while (should_while_loop_keep_looping_true_means_not_selected_gender)
        {
            cout << "Wybierz płeć (m / k): ";
            should_while_loop_keep_looping_true_means_not_selected_gender = false;
            //switch (_getch()) {
            switch ('m') {
                case 'm': case 'M':
                    is_man = true;
                    break;
                case 'k': case 'K':
                    is_man = false;
                    break;
                default:
                    should_while_loop_keep_looping_true_means_not_selected_gender = true;
            }
        }

        ProfessionType profession_type;

        bool should_while_loop_keep_looping_true_means_not_selected_profession = true;
        while (should_while_loop_keep_looping_true_means_not_selected_profession)
        {
            cout << "Witaj " + nick + "!\n"
                                      "Wybierz profesję: \n"
                                      "    1. Łowca (Atak z dystansu(2), trucizna, unik)\n"
                                      "    2. Wojownik (Silny atak, blok tarczą, wytrzymały)\n"
                                      "    3. Mag (Atak z dystansu(1), leczenie ran, ataków nie da się uniknąć / zablokować):\n";
            should_while_loop_keep_looping_true_means_not_selected_profession = false;
            //switch (_getch()) {
            switch ('2') {
                case '1':
                    profession_type = HUNTER;
                    break;
                case '2':
                    profession_type = WARRIOR;
                    break;
                case '3':
                    profession_type = MAGICIAN;
                    break;
                default:
                    should_while_loop_keep_looping_true_means_not_selected_profession = true;
            }
        }

        hero = new Hero(nick, is_man, profession_type, true);
    }

    explicit Profile(const string &filename)
    {
        if (!filesystem::exists(filename))
            create_new();
        else
            load_from_file(filename);

    }

    ~Profile()
    {
        delete hero;

    }


    bool load_from_file(const string &filename)
    {
        // hero = new Hero();
        return 1;

    }

    bool save_to_file()
    {
        return 1;

    }
};
