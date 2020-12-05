#pragma once

#include <iostream>
#include <vector>

#include "profile.cpp"
#include "game.cpp"

using namespace std;

int main()
{
    Profile profile("main.profile");
    Game game(profile);
    game.start();

}