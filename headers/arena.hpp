#pragma once

#include "hero.hpp"

enum class FightResult { WIN, DEFEAT, DRAW };

// Perform fights.
class Arena
{
    Graphic graphic;
public:
    Arena(Graphic &graphic) : graphic(graphic) {};

    // Returns true, when made a move, false when someone died.
    bool do_move(Entity &active_entity, Entity &passive_entity);

    FightResult fight(Hero &hero, Entity &enemy);

};
