#include <iostream>

#include "../headers/game.hpp"

using std::clog;
using std::cout;
using std::endl;


void Game::dummy_game_loop()
{
    std::string map_file = "textures\\maps\\test_map.tga";
    std::string data_file = "start_map.data";

    map.load_texture(map_file);
    //map.load_data(data_file);

    graphic.load_level(map);


    // run the program as long as the window is open
    while (graphic.window->isOpen())
    {
        control.parse_events(graphic);

        graphic.update();
        graphic.window->display();
    }
}


Game::Game():
    graphic(Graphic()),
    profile(Profile()),
    control(Control())
    // map(Map())
{
    clog << "Initializing graphics..." << endl;
    dummy_game_loop();
};



void Game::start()
{
    cout << "Starting game." << endl;

    clog << "Choosing profile... " << profile.name << endl;
    profile = choose_profile();
    cout << "Chosen profile: " << profile.name << endl;


    clog << "Loading profile..." << endl;
    profile.load();
    clog << "Loaded profile, nick: " << profile.hero.name << endl;
    //clog << "lvl: "<< profile.hero.lvl<<"\nexp: " << profile.hero.exp << "\nhp: " << profile.hero.hp << "\nhp_max: " << profile.hero.hp_max << "\nmana: " << profile.hero.mana << "\nstamina: " << profile.hero.stamina << "\nstrength: " << profile.hero.strength << "\nagility: " << profile.hero.agility << "\nintelect: " << profile.hero.intelect << "\nblock: " << profile.hero.block << "\ndefence: " << profile.hero.defence << "\nAT: " << profile.hero.attack_time << "\n";


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
