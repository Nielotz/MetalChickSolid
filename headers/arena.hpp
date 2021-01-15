#pragma once

#include "graphic.hpp"
#include "profile.hpp"
#include "enemy.hpp"

enum class FightResult { WIN, DEFEAT, DRAW };

// Perform fights.
class Arena
{
public:
    void fight(Hero& hero, Enemy& enemy);

    // Returns true, when made a move, false when someone died.
    //bool do_move(Entity& active_entity, Entity& passive_entity);

    //FightResult fight(Hero& hero, Entity& enemy);

private:
    void attack(Hero& hero, Enemy& enemy, int32_t who_attack);
    void hero_defence(Hero& hero, int32_t stamina);
    int32_t losu();
};
