#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

enum TileType { NPC=1, ENEMY=2, TERRAIN=3, ITEM=4 };

struct TileData
{
    TileType type;
    bool is_walkable;
    unsigned char console_color_modifier;

    TileData() = default;

    TileData(TileType type, bool is_walkable, char console_color_modifier)
    : type(type), is_walkable(is_walkable), console_color_modifier(console_color_modifier)
    {}
};

/*
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
*/

const unordered_map<int, TileData> TILE{
        pair<int, TileData>(0, TileData(TileType::TERRAIN, true, 40)), // Black = terrain.
        pair<int, TileData>(0xFF0000, TileData(TileType::ENEMY, false, 41)), // Red = enemy.
        pair<int, TileData>(0x00FF00, TileData(TileType::ITEM, false, 42)), // Green = Item.
        pair<int, TileData>(0x0000FF, TileData(TileType::NPC, false, 44)), // Blue = NPC.
        pair<int, TileData>(0xFFFFFF, TileData(TileType::TERRAIN, false, 47)), // White = Border.
};


struct Map
{
    uint16_t img_size_x = 0;
    uint16_t img_size_y = 0;
    vector<string> tiles;

    explicit Map(const string& map_filename)
    {
        load_from_file(map_filename);
    }

    // Model on:
    // https://stackoverflow.com/questions/9296059/read-pixel-value-in-bmp-file
    // Image max size = 255 x 255.
    // Return whether succesfully load map.
    bool load_from_file(const string& path)
    {
        // Images are encoded from bottom to the top, so they are flipped.
        FILE *file = nullptr;
        fopen_s(&file, path.c_str(), "rb");

        if (file == nullptr)
        {
            cout << "Nie można otworzyć pliku: " << path << endl;
            throw;
        }

        // First 54 bytes of BMP file contains headers.
        uint8_t info[54];
        fread(info, sizeof(uint8_t), 54, file); // read the 54-byte header

        // extract image height and width from header
        img_size_x = *(int32_t*)&info[18];
        img_size_y = *(int32_t*)&info[22];

        int32_t color_depth = *(int16_t*)&info[28];

        cout << "Loading map... " << endl;
        cout << "       Name: " << path << endl;
        cout << "      Width: " << img_size_x << endl;
        cout << "     Height: " << img_size_y << endl;

        if (color_depth != 24)
        {
            cout << "Głebia barw musi być równa 24: " << path << endl;
            throw;
        }

        int row_padded = (img_size_x * 3 + 3) & (~3);
        auto* data = new uint8_t[row_padded];

        tiles.resize(img_size_y);
        for (int y = 0; y < img_size_y; y++)
        {
            tiles[y].resize(img_size_x * 3);
            fread(data, sizeof(uint8_t), row_padded, file);
            // cout << "RED: " << int(data[2]) << "  GREEN: " << int(data[1]) << "  BLUE: " << int(data[0]);
            for (int x = 0; x < img_size_x * 3; x += 3)
            {
                // Encoded like (B, G, R)

                // std::unordered_map<int, TileData>::const_iterator
                auto found = TILE.find (((unsigned int)(data[x+2]) << 16) +
                        ((unsigned int)(data[x+1]) << 8)
                        + (unsigned int)(data[x+2]));
                if (found == TILE.end())
                    tiles[y][x] = 0;
                else {
                    tiles[y][x] = found->second.console_color_modifier;
                }
            }
            cout << endl;
        }

        fclose(file);
        return data;
    }

};

