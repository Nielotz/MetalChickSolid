#include "../../headers/entity.hpp"

uint64_t Entity::ID = 0;

bool Entity::move(Direction& direction)
{
    return false;
}

Entity::Entity()
    :id(ID++)
{ }

Entity::Entity(Entity& entity) :
    id(entity.id),
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