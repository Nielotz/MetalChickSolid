#include "../../headers/enemy.hpp"

Bear::Bear()
{
    name = "Bear";
    hp = 10;
    stamina = 3;
    critical = 2;
    strength = 1;
    attack_time = 1;
    defence = 2;

    typedef std::pair<uint8_t, Item> chance_item;
    loot.push_back(chance_item{ 70, Meat() });
    loot.push_back(chance_item{ 40, FancyMeat() });
}

Enemy::Enemy()
{
}

Enemy::Enemy(const Enemy&)
{
}
