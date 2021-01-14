#include "../../headers/entity.hpp"

bool Entity::move(Direction& direction)
{
    return false;
}

Entity::Entity(const Entity& entity) :
    name(entity.name),
    position(entity.position),
    profession_type(entity.profession_type),
    lvl(entity.lvl),
    exp(entity.exp),
    hp(entity.hp),
    hp_max(entity.hp_max),
    mana(entity.mana),
    stamina(entity.stamina),
    strength(entity.strength),
    agility(entity.agility),
    intelect(entity.intelect),
    critical(entity.critical),
    critical_power(entity.critical_power),
    block(entity.block),
    defence(entity.defence),
    attack_time(entity.attack_time)
{ }