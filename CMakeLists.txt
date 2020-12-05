cmake_minimum_required(VERSION 3.17)
project(RPG_school_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPG_school_project
        game.cpp
        hero.cpp
        main.cpp profile.cpp profession.cpp)
