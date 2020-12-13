#pragma once
#define _HAS_STD_BYTE 0

#include <random>
#include <limits>

#include "hero.cpp"

enum FightResult {WIN, DEFEAT, DRAW};


class Arena
{
public:
    std::default_random_engine generator;
    std::uniform_int_distribution<int> small_distribution;
    std::uniform_int_distribution<int> big_distribution;

    Arena()
    {
        small_distribution = std::uniform_int_distribution<int> (90, 110);
        big_distribution = std::uniform_int_distribution<int>(0, 100);
    }

    // Returns true, when made a move, false when someone died.
    bool do_move(Entity& active_entity, Entity& passive_entity)
    {
        int64_t hit = active_entity.hit * small_distribution(generator) / 100.;
        if (big_distribution(generator) < passive_entity.dodge_chance)
            cout << "Uskok!" << endl;
        else if (big_distribution(generator) < passive_entity.block_chance)
            cout << "Blok!" << endl;
        else if (big_distribution(generator) < passive_entity.critic_hit_chance)
        {
            hit *= 3; // Change to received from hero data.
            if (hit > (std::numeric_limits<int32_t>::max)())
                hit = (std::numeric_limits<int32_t>::max)() - 1;
            cout << "Cios krytyczny!" << endl;
        }
        cout << "Uderzono za " << hit << ". Pozostało życia: " << passive_entity.hp << endl;
        passive_entity.hp -= hit;
        return passive_entity.hp > 0;
    }

    FightResult fight(Hero& hero, Entity&& enemy)
    {
        return fight(Hero(hero), enemy);
    }

    FightResult fight(Hero&& hero, Entity& enemy)
    {
        // Whose number is bigger - attacks.
        uint16_t hero_attack_time = hero.attack_time;
        uint16_t enemy_attack_time = enemy.attack_time;

        for (uint8_t turn_number = 0; turn_number < 100; turn_number++)
        {
            // Hero has a move.
            if (hero_attack_time <= enemy_attack_time)
            {
                cout << "Twoja tura" << endl;
                hero_attack_time += hero.attack_time;
                if ( ! do_move(hero, enemy))
                    break;
            }
            // Enemy has a move.
            else
            {
                cout << "Tura przeciwnika" << endl;
                enemy_attack_time += enemy.attack_time;
                if ( ! do_move(enemy, hero))
                    break;
            }
        }
        if (enemy.hp > 0)
            return hero.hp > 0 ? FightResult::DRAW : FightResult::DEFEAT;
        return FightResult::WIN;
    }
};