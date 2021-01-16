#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "../headers/arena.hpp"

void Arena::fight(Hero& hero, Enemy& enemy, Graphic& graphic)
{
    int32_t tura = 1;
    int32_t heroAT = hero.attack_time;
    int32_t enemyAT = enemy.attack_time;
    //Obra¿enia = (strength lub intelect) + (obra¿enia broni) - (Obrona przeciwnika)
    int32_t enemyMaxStamina = enemy.stamina;
    int32_t heroMaxStamina = 20 * hero.lvl + 3 * hero.agility;
    srand(((int32_t)time(NULL)));
    std::cout << "\nStaty Hero:\nhp: " << hero.hp << "/" << hero.hp_max << "\nStamina: " << hero.stamina << "/" << heroMaxStamina << "\nAT:" << heroAT << " S:" << hero.strength << " A:" << hero.agility << " lvl:" << hero.lvl << "\n";
    std::cout << "\nStaty Enema:\nhp: " << enemy.hp << "/" << enemy.hp_max << "\nStamina: " << enemy.stamina << "/" << enemyMaxStamina << "\nAT:" << enemyAT << " S:" << enemy.strength << " A:" << enemy.agility << " lvl:" << enemy.lvl << "\n";
    //temp - do usuniêcia przy implementacji w grafike
    char znak;
    ////////
    while (hero.hp > 0 && enemy.hp > 0)
    {
        if (enemy.stamina < 0)
            enemy.stamina = 0;
        if (hero.stamina < 0)
            hero.stamina = 0;
        std::cout << "\nTura " << tura << ":\n";
        std::cout << "\nHero: hp: " << hero.hp << "/" << hero.hp_max << "; Stamina: " << hero.stamina << "/" << heroMaxStamina << "; AT:" << heroAT << " S:" << hero.strength << " A:" << hero.agility << " lvl:" << hero.lvl << "\n";
        std::cout << "Enem: hp: " << enemy.hp << "/" << enemy.hp_max << "; Stamina: " << enemy.stamina << "/" << enemyMaxStamina << "; AT:" << enemyAT << " S:" << enemy.strength << " A:" << enemy.agility << " lvl:" << enemy.lvl << "\n";
        if (heroAT > enemyAT)
        {   //enem podejmuje akcje
            if ((hero.hp - (enemy.strength - (hero.agility + hero.strength) / 100)) <= 0)
            {
                std::cout << "Przeciwnik cie atakuje\n";
                attack(hero, enemy, 2);
            }
            else if (enemy.hp < (enemy.hp_max * 0.15) || enemy.stamina < (enemyMaxStamina * 0.2))
            {
                std::cout << "Przeciwnik sie broni\n";
                enemy.stamina += (int32_t)(enemyMaxStamina * 0.25);
                enemy.hp += (int32_t)(enemy.hp_max * 0.25);
                std::cout << "Przeciwnik odzyskuje " << (int32_t)(enemyMaxStamina * 0.25) << " staminy i " << (int32_t)(enemy.hp_max * 0.25) << " hp\n";
                if (enemy.hp > enemy.hp_max)
                    enemy.hp = enemy.hp_max;
                if (enemy.stamina > enemyMaxStamina)
                    enemy.stamina = enemyMaxStamina;
            }
            else
            {
                std::cout << "Przeciwnik cie atakuje\n";
                attack(hero, enemy, 2);
            }
            enemyAT += enemy.attack_time;
        }
        else
        {   //hero podejmuje akcje
            std::cout << "Jaka akcje chcesz podjac? z-atak,x-obrona,c-ucieczka\n";
            //std::cin >> znak;
            ARENA_BUTTON znak_gui = wait_for_button(graphic);
            //std::cout << "wybrales " << znak << std::endl;
            if (znak_gui == ARENA_BUTTON::ATTACK)
            {
                if (hero.stamina > 0)
                {
                    std::cout << "Atakujesz\n";
                    attack(hero, enemy, 1);
                }
                else
                {
                    std::cout << "Masz niewystarczajaca ilosc staminy do ataku.\n";
                    hero_defence(hero, heroMaxStamina);
                }

            }
            else if (znak_gui == ARENA_BUTTON::DEFENCE)
            {
                //obrona
                hero_defence(hero, heroMaxStamina);
            }
            else if (znak_gui == ARENA_BUTTON::RUN_AWAY) {
                //ucieczka
                std::cout << "Uciekasz z pola walki...\n";
                enemy.hp = enemy.hp_max;
                enemy.stamina = enemyMaxStamina;
                break;
            }
            heroAT += hero.attack_time;
        }
        tura++;
    }
    std::cout << "Koniec walki\n";
    if (hero.hp <= 0)
        std::cout << "Haha you died\n";
    else
    {
        std::cout << "Pokonales przeciwnika!\n";
        enemy.status = 0;
    }
}

void Arena::attack(Hero& hero, Enemy& enemy, int32_t who_attack)
{
    int32_t heroAdvantage = 0;
    int32_t enemyAdvantage = 0;
    if ((hero.lvl - enemy.lvl) > 5)//Ró¿nica lvl
        heroAdvantage += hero.lvl - enemy.lvl;
    else if ((enemy.lvl - hero.lvl) > 5)
        enemyAdvantage += enemy.lvl - hero.lvl;

    if (who_attack == 1)
    {   //hero atakuje
        if (losu() <= enemy.block) //Szansa na pe³ny blok enema
        {   //Pe³ny blok siê uda³
            std::cout << "Przeciwnik wykonal pe³n¹ obrone. Nie zadajesz mu obrazen\n";
            enemy.stamina -= hero.strength; //Ew. hero.strength + sword.damage
        }
        else
        {   //Pe³ny blok siê nie uda³
            if (losu() <= (hero.agility * 0.03 + 0.03 * heroAdvantage))//szansa na cios krytyczny
            {   //Cios krytyczny
                std::cout << "Zadajesz przeciwnikowi cios krytyczny\n";
                enemy.hp -= (int32_t)(hero.strength + 0.01 * heroAdvantage);
                std::cout << "Zadajesz przeciwnikowi " << (int32_t)(hero.strength + 0.01 * heroAdvantage) << " punktow obrazen\n";
            }
            else //Zwyk³y cios
            {
                enemy.hp -= hero.strength - hero.strength * ((enemy.agility + enemy.strength) / 100);
                std::cout << "Zadajesz przeciwnikowi " << hero.strength - hero.strength * ((enemy.agility + enemy.strength) / 100) << " punktow obrazen\n";
            }
        }
        hero.stamina -= hero.strength * 2;
    }
    else
    {   //enem atakuje
        if (losu() <= hero.block) //Szansa na pe³ny blok enema
        {   //Pe³ny blok siê uda³
            std::cout << "Udalo ci sie wykonac pelna obrone. Nie otrzymujesz obrazen\n";
            hero.stamina -= enemy.strength; //Ew. hero.strength + sword.damage
        }
        else
        {   //Pe³ny blok siê nie uda³
            if (losu() <= (enemy.agility * 0.03 + 0.03 * enemyAdvantage))//szansa na cios krytyczny
            {   //Cios krytyczny
                std::cout << "Przeciwnik zadaje ci cios krytyczny\n";
                hero.hp -= (int32_t)(enemy.strength + 0.01 * enemyAdvantage);
                std::cout << "Przeciwnik zadaje ci " << (int32_t)(enemy.strength + 0.01 * heroAdvantage) << " punktow obrazen\n";
            }
            else //Zwyk³y cios
            {
                hero.hp -= enemy.strength - enemy.strength * ((hero.agility + hero.strength) / 100);
                std::cout << "Przeciwnik zadaje ci " << enemy.strength - enemy.strength * ((hero.agility + hero.strength) / 100) << " punktow obrazen\n";
            }
        }
        enemy.stamina -= enemy.strength * 2;
    }
}

void Arena::hero_defence(Hero& hero, int32_t stamina)
{
    std::cout << "Bronisz sie\n";
    hero.stamina += (int32_t)(stamina * 0.25);
    hero.hp += (int32_t)(hero.hp_max * 0.25);
    std::cout << "Odzyskujesz " << (int32_t)(stamina * 0.25) << " staminy i " << (int32_t)(hero.hp_max * 0.25) << " hp\n";
    if (hero.hp > hero.hp_max)
        hero.hp = hero.hp_max;
    if (hero.stamina > stamina)
        hero.stamina = stamina;
}

int32_t Arena::losu()
{
    return int32_t(rand() % 100 + 1);
}

ARENA_BUTTON Arena::wait_for_button(Graphic& graphic)
{
    ARENA_BUTTON znak_gui = ARENA_BUTTON::NONE;
    while (znak_gui != ARENA_BUTTON::NONE)
    {
        znak_gui = Control().check_arena_button_clicked(graphic);
        graphic.update();
        graphic.window->display();
    }
    return znak_gui;
}
