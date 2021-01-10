#include "../../headers/hero.hpp"
#include <math.h>

void Hero::increase_lvl()
{
    lvl += 1;
    update_attributes();
}

void Hero::update_attributes()
{
    double baza = pow(lvl, 1.25);
    hp_max = (int32_t)(20 * baza + 5 * strength);
    if (profession_type == ProfessionType::WARRIOR) {
        strength = (int32_t)(5 * baza);
    }
    else {
        strength = (int32_t)(3 * baza);
    }
    if (profession_type == ProfessionType::HUNTER) {
        agility = (int32_t)(5 * baza);
    }
    else {
        agility = (int32_t)(3 * baza);
    }
    if (profession_type == ProfessionType::MAGICIAN) {
        intelect = (int32_t)(5 * baza);
    }
    else {
        intelect = (int32_t)(3 * baza);
    }
    mana = (int32_t)(20 * lvl + 3 * intelect);
    stamina = (int32_t)(20 * lvl + 3 * agility);
    block = (int32_t)(strength / 2);
    defence = (int32_t)(agility + strength);
    attack_time = (int32_t)(100 / agility);
}

