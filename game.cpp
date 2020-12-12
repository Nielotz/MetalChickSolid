#pragma once

#include "profile.cpp"
#include "graphic.cpp"
#include "map.cpp"
#include "item.cpp"
#include "weapon.cpp"

class Game
{

public:
    const Profile *profile;
    Graphic graphic;
    std::shared_ptr<Map> map;
    Items items;

    void start()
	{
		cout << "Starting game.";
        // graphic.load_map(map);
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

        graphic.clear_screen();
        graphic.print_with_timeout_between_chars("Witaj " + profile->hero->nick + "!\n", 100);
        profile->hero->print_stats_card(graphic); // TODO: move into graphic.

	};
};