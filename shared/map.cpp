#include <iostream>
#include <fstream>

#include "../headers/map.hpp"
#include "../headers/consts.hpp"

Map::Map(std::string& path_to_data_file)
{
}

void Map::load_texture(const char* path)
{
    std::string temp;
    temp += path;
    load_texture(temp);
}

void Map::load_map_data(const char* path)
{
    std::string temp;
    temp += path;
    load_map_data(temp);
}

void Map::load_map_data(string& path)
{
    /*
    data = new MapData();
    std::string enemy_name_read_from_file = "Boberek";
    if (enemy_name_read_from_file == "Skoczek narciarski")
    {

    }
    else if (enemy_name_read_from_file == "Boberek")
    {
        Boberek boboerek;
        data->entities.push_back(boberek);

    }
    */
}

void Map::load_map_collisions(string& path)
{
    std::string true_path = path;
    std::ifstream testing_file(path.c_str());
    if (testing_file.good() == 0)
        true_path = PATH::MAP::TEXTURES::TEST;
    testing_file.close();

    if (true_path == PATH::MAP::TEXTURES::TEST)
        true_path = "textures\\maps\\test_map.txt";
    else if (true_path == PATH::MAP::TEXTURES::START)
        true_path = "textures\\maps\\start_map.txt";
    else if (true_path == PATH::MAP::TEXTURES::FOREST)
        true_path = "textures\\maps\\forest_map.txt";
    else if (true_path == PATH::MAP::TEXTURES::BOSS)
        true_path = "textures\\maps\\boss_map.txt";
    std::ifstream infile(true_path);
    std::string line;
    collisions.clear();
    while (std::getline(infile, line)) {
        collisions.push_back(line);
    }

}

void Map::save_load_dead_enemies()
{
    //F for all fallen animals during battle [*]

    std::string path = "textures\\mobs\\dead_enemies.txt";
    if (dead_enemies.empty())
    {
        std::ifstream infile(path);
        std::string line;
        while (std::getline(infile, line)) {
            dead_enemies.push_back(line);
        }
        if (dead_enemies.empty()) {
            dead_enemies.push_back(" ");
            dead_enemies.push_back(" ");
            dead_enemies.push_back(" ");
        }
    }
    else {
        std::ofstream save_file;
        save_file.open(path);
        save_file << dead_enemies[0] << "\n";
        save_file << dead_enemies[1] << "\n";
        save_file << dead_enemies[2] << "\n";
        save_file.close();
        std::cout << "enemies saved.\n";
    }

}

void Map::load_texture(string& path)
{
    if (!texture.loadFromFile(path))
        throw std::runtime_error("Cannot load " + path);

    tiles_number = {
        texture.getSize().x / CONSTS::TILE_SIZE_ON_TEXTURE_MAP,
        texture.getSize().y / CONSTS::TILE_SIZE_ON_TEXTURE_MAP };

    texture.setSmooth(true);
    sprite.setTexture(texture);
}
