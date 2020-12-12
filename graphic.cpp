#pragma once
#define _HAS_STD_BYTE 0
#include <windows.h>
#include <iostream>
#include "map.cpp"

class Graphic
{
    void set_cursor_at(uint16_t x, uint16_t y)
    {

    }
    //vector<string> screen;

public:

    Graphic()
    {
        // TODO: Change to autofit screen. Requires: resizing console.
        //screen.resize(100);
    }

    //void load_map(shared_ptr<Map> map)
    //{
//
    //}

    //void draw()
    //{
    //    for (auto& row : screen)
    //    {
    //        if (row.empty())
    //            break;
    //        cout << row << endl;
    //    }
    //}

    //void load_welcome_screen(Hero *hero)
    //{
    //    //screen[0] = "Witaj w \"Grze\" " + hero->nick + "!";

    //}

    void show_menu()
    {
        cout << "'q' - wyjdź z gry \n"
                "'a' - znajdz walkę \n ";
    }

    void clear_screen()
    {
        printf("\033c");
    }

    void print_with_timeout_between_chars(std::string &&message, DWORD sleep_time)
    {
        for (auto chr : message)
        {
            putchar(chr);
            Sleep(sleep_time);
        }
    }

};
