#include "../headers/game.hpp"

#include <iostream>


using std::clog;
using std::cout;
using std::endl;


Game::Game():
graphic(Graphic(Hero())),
profile(Profile()),
control(Control()),
arena(Arena(graphic)),
map(Map())
{
    clog << "Initializing graphics..." << endl;
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
    Profile dummy_profile;
    dummy_profile.path = "test_profile.txt";
    return dummy_profile;
}

void Game::stop()
{
}
