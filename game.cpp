#pragma once
#define _HAS_STD_BYTE 0
#include "profile.cpp"
#include "graphic.cpp"
#include "map.cpp"
#include "item.cpp"
#include "weapon.cpp"
#include "control.cpp"

class Game
{
    void game_loop()
    {
        graphic.show_menu();
        char choose = control.get_char_from_range("aq");
        switch (choose) {
            case 'q':
                return;
            case 'a':
                break;
            default:
                throw;
        }
    }

    void find_enemy()
    {

    }

public:
    const Profile *profile;
    Graphic graphic;
    Control control;
    std::shared_ptr<Map> map;
    Items items;

    void start()
	{
		cout << "Starting game.";
        // graphic.load_map(map);

        graphic.clear_screen();
        graphic.print_with_timeout_between_chars("Witaj " + profile->hero->nick + "!\n", 100);
        profile->hero->print_stats_card(graphic); // TODO: move into graphic.

        game_loop();
        stop();
	}

	void stop()
	{

	}

	explicit Game(const Profile *profile, const string &map_filename)
	: profile(profile)
	{
        items = Items();
        items.weapons.reserve(3);
        items.weapons.emplace_back("Magiczny miecz", 10, ProfessionType::WARRIOR);

        items.weapons.emplace_back("Magiczny łuk", 3, ProfessionType::HUNTER);
        // Strzela łukiem nie strzałami.
        // items.weapons.emplace_back("Magiczne strzały", 2, ProfessionType::HUNTER);

        items.weapons.emplace_back("Magiczna różdżka", 3, ProfessionType::MAGICIAN);

        graphic = Graphic();
        // map = std::make_shared<Map>(map_filename);
        // graphic.load_map(map);

        // graphic.load_welcome_screen(profile->hero);
        // graphic.draw();
	};
};