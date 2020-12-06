#pragma once

#include <iostream>
#include <vector>

#include "profile.cpp"
#include "game.cpp"

using namespace std;

int main()
{
    system("chcp 65001");
    Profile profile("main.profile");
    Game game(profile);
    game.start();

}