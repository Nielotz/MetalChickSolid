#pragma once

#include <iostream>

#include "../headers/game.hpp"


using std::clog;
using std::cout;
using std::endl;


Game::Game()
{
    clog << "Initializing graphics..." << endl;
    graphic = Graphic();
};



void Game::main_loop()
{
    while (is_running)
    {

    }
}

void Game::start()
{
    cout << "Starting game." << endl;

    clog << "Choosing profile... " << profile.name << endl;
    profile = choose_profile();
    cout << "Chosen profile: " << profile.name << endl;

    clog << "Loading profile..." << endl;
    profile.load();
    clog << "Loaded profile, nick: " << profile.hero.nick << endl;

    clog << "Loading maps..." << endl;
    map.load_maps("test_map");
    cout << "Loaded maps." << endl;

    clog << "Loading map into the graphic..." << endl;
    graphic.load_map(map);
    cout << "Loaded map." << endl;


    main_loop();
    stop();
}

Profile Game::choose_profile()
{
    std::string dummy_string = std::string("test_profile.txt");
    Profile dummy_profile;
    dummy_profile.path = dummy_string;
    return dummy_profile;
}

void Game::stop()
{
    /// Save profile;
}
