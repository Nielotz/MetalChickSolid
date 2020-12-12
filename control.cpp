#pragma once
#define _HAS_STD_BYTE 0
#include <iostream>
#include <conio.h>

// Handles input events.
class Control
{
public:

    Control()
    {}

    int64_t get_char_from_range(std::string &&range)
    {
        int64_t chr;
        do{
            chr = _getch();
        }while (range.find(chr) == std::string::npos);

        return chr;
    }

};