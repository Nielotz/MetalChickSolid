cmake_minimum_required(VERSION 3.17)
project(RPG_school_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPG_school_project
        main.cpp
        graphic/graphic.cpp headers/graphic.hpp
        shared/map.cpp headers/map.hpp
        headers/position.hpp
        shared/tile.cpp headers/tile.hpp
        engine/profile.cpp headers/profile.hpp
        engine/Entity/entity.cpp headers/entity.hpp
        headers/profession.hpp
        headers/direction.hpp
        engine/Entity/hero.cpp headers/hero.hpp
        headers/status.hpp
        engine/arena.cpp headers/arena.hpp
        headers/rng.hpp
        engine/game.cpp headers/game.hpp
        engine/Items/item.cpp headers/item.hpp
        control/control.cpp headers/control.hpp
        )