#pragma once

#include <iostream>

#include "profile.cpp"
#include "game.cpp"

#include <unordered_map>

using namespace std;

int main()
{
    system("chcp 65001");
    Profile profile("main_profile.txt");
    string map_filename("test_map.bmp"); // Move into profile.
    Game game(&profile, map_filename);
    game.start();

}