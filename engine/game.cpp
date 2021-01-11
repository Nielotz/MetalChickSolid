#include <iostream>

#include "../headers/game.hpp"
#include "../headers/consts.hpp"

using std::clog;
using std::cout;
using std::endl;


void Game::game_loop()
{
    std::string map_file = PATH::MAP::TEXTURES::START;
    //std::string data_file = "start_map.data";

    map.load_texture(map_file);
    //map.load_data(data_file);

    profile.hero.position = Position(0, 1);

    graphic.load_level(map);

    graphic.load_hero_textures(profile.hero, PATH::HERO::TEXTURES::warrior);


    // run the program as long as the window is open
    while (graphic.window->isOpen())
    {
        control.parse_move_events(graphic, *this);

        graphic.update();
        graphic.window->display();
    }
}


Game::Game() :
    graphic(Graphic(profile.hero))
{
    clog << "Initializing graphics..." << endl;
    game_loop();
};



void Game::start()
{
    cout << "Starting game." << endl;

    clog << "Choosing profile... " << profile.name << endl;
    choose_profile(profile);
    cout << "Chosen profile: " << profile.name << endl;


    clog << "Loading profile..." << endl;
    profile.load();
    clog << "Loaded profile, nick: " << profile.hero.name << endl;
    //clog << "lvl: "<< profile.hero.lvl<<"\nexp: " << profile.hero.exp << "\nhp: " << profile.hero.hp << "\nhp_max: " << profile.hero.hp_max << "\nmana: " << profile.hero.mana << "\nstamina: " << profile.hero.stamina << "\nstrength: " << profile.hero.strength << "\nagility: " << profile.hero.agility << "\nintelect: " << profile.hero.intelect << "\nblock: " << profile.hero.block << "\ndefence: " << profile.hero.defence << "\nAT: " << profile.hero.attack_time << "\n";


    stop();
}

void Game::choose_profile(Profile& profile)
{
    profile.path = "test_profile.txt";
}

void Game::stop()
{
}

void Game::move_hero(const Direction& direction)
{

    if (direction == Direction::LEFT)
    {
        if (true)
        {
            graphic.move_hero(Direction::LEFT);
            profile.hero.position.x--;
        }
    }
    else if (direction == Direction::RIGHT)
    {
        if (true)
        {
            graphic.move_hero(Direction::RIGHT);
            profile.hero.position.x++;
        }

    }
    else if (direction == Direction::TOP)
    {
        if (true)
        {
            graphic.move_hero(Direction::TOP);
            profile.hero.position.y--;
        }
    }
    else // BOTTOM
    {
        if (true)
        {
            graphic.move_hero(Direction::BOTTOM);
            profile.hero.position.y++;
        }
    }

}
