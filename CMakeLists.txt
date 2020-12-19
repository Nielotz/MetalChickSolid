cmake_minimum_required(VERSION 3.17)
project(RPG_school_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPG_school_project
        main.cpp
        control/control.cpp headers/control.hpp
        engine/Entity/entity.cpp headers/entity.hpp
        engine/Entity/hero.cpp headers/hero.hpp
        engine/Items/item.cpp headers/item.hpp
        engine/Items/weapon.cpp headers/weapon.hpp
        engine/arena.cpp headers/arena.hpp
        engine/game.cpp headers/game.hpp
        engine/profile.cpp headers/profile.hpp
        graphic/graphic.cpp headers/graphic.hpp
        shared/map.cpp headers/map.hpp
        shared/tile.cpp headers/tile.hpp
        headers/enemy.hpp

        headers/position.hpp
        headers/profession.hpp
        headers/direction.hpp
        headers/status.hpp
        headers/rng.hpp)