#pragma once
#define _HAS_STD_BYTE 0
#include "profile.cpp"
#include "graphic.cpp"
#include "map.cpp"
#include "item.cpp"
#include "weapon.cpp"
#include "control.cpp"
#include "arena.cpp"
#include "enemy.cpp"
#include "status.cpp"

class Game
{
    GameStatus game_loop()
    {
        while (true)
        {
            graphic.clear_screen();
            graphic.show_menu();
            char choose = control.get_char_from_range("aqp");
            if (choose == 'q')
                return GameStatus::PLAYER_EXIT;
            else if (choose == 'p')
            {
                profile->hero->print_stats_card(graphic);

                // TODO: move that into seperate thing.
                cout << "Naciśnij dowolny klawisz by przejść dalej:";
                control.wait_for_user_interaction();
            }
            // TODO: split into different function.
            else if (choose == 'a')
            {
                FightResult fight_result = arena.fight(*profile->hero, find_enemy());

                if (fight_result == FightResult::DEFEAT)
                    return GameStatus::HERO_DIED;
                else if (fight_result == FightResult::DRAW)
                    cout << "Remis!" << endl;
                else // FightResult::DRAW
                {
                    cout << "Wygrałeś!" << endl;
                    profile->hero->exp += 5;
                    while (profile->hero->exp > profile->hero->lvl * 2)
                    {
                        profile->hero->increase_lvl();
                        profile->hero->exp -= profile->hero->lvl * 2;
                    }
                    cout << "Pozostałe doświadczenie: " << profile->hero->exp << endl;
                }
                cout << "Naciśnij dowolny klawisz by przejść dalej:";
                control.wait_for_user_interaction();
            }
            else
                throw;
        }
    }

    Enemy find_enemy()
    {
        return Beaver(-20 + profile->hero->lvl, profile->hero);
    }

public:
    const Profile *profile;
    Graphic graphic;
    Control control;
    Arena arena;
    std::shared_ptr<Map> map;
    Items items;

    void start()
	{
		cout << "Starting game.";
        // graphic.load_map(map);

        graphic.clear_screen();
        graphic.print_with_timeout_between_chars("Witaj " + profile->hero->nick + "!\n", 100);
        profile->hero->print_stats_card(graphic); // TODO: move into graphic.

        cout << "Naciśnij dowolny klawisz by przejść dalej:";
        control.wait_for_user_interaction();

        GameStatus status = game_loop();
        if (status == GameStatus::PLAYER_EXIT)
        {
            stop();
            return;
        }
        else if (status == GameStatus::HERO_DIED)
        {
            graphic.show_hero_dead_screen();
            cout << "Naciśnij dowolny klawisz aby wyjść";
            getchar();
        }
	}

	void stop()
	{

	}

	explicit Game(const Profile *profile, const string &map_filename)
	: profile(profile)
	{
        arena = Arena();
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