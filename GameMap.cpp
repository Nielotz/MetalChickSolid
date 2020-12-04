#include <windows.h>
#include <string>
#include <iostream>
#include <vector>

#include "logging.cpp"

using namespace std;



class GameMap
{
public:
    const string name;
    size_t map_size_x;
    size_t map_size_y;

	GameMap(const string& path, const string& name)
        :name(name)
	{
        load_from_file(path);
	}

    void load()
    {
        SMALL_RECT map_size = {0, 0};
        
        //SetConsoleWindowInfo(GetConsoleWindow(), true, );
    }
    
        // Model on:
    // https://stackoverflow.com/questions/9296059/read-pixel-value-in-bmp-file
    // Image max size = 255 x 255.
    // Return whether succesfully load map.
    bool load_from_file(const string path)
    {
        FILE *file = NULL;
        fopen_s(&file, path.c_str(), "rb");

        if (file == NULL)
        {
            Logger::error("Cannot open '" + path + "'file!");
            return 0;
        }

        uint8_t info[54];
        size_t len_of_read_data = fread(info, sizeof(uint8_t), 54, file); // read the 54-byte header

        // extract image height and width from header
        int32_t width = *(int32_t*)&info[18];
        int32_t height = *(int32_t*)&info[22];
        int32_t color_depth = *(int16_t*)&info[28];
        int32_t image_size = *(int16_t*)&info[34];

        cout << "Loading map... " << endl;
        cout << "       Name: " << path << endl;
        cout << "      Width: " << width << endl;
        cout << "     Height: " << height << endl;
        cout << "Color depth: " << color_depth << endl;
        map_size_x = width;
        map_size_y = height;
        if (color_depth != 24)
        {
            Logger::error("Color depth of map image has to be 24 bit!");
            return 0;
        }

        int row_padded = (width * 3 + 3) & (~3);
        uint8_t* data = new uint8_t[row_padded];
        uint8_t tmp;

        for (int i = 0; i < height; i++)
        {
            fread(data, sizeof(uint8_t), row_padded, file);
            for (int j = 0; j < width * 3; j += 3)
            {
                // Convert (B, G, R) to (R, G, B)
                tmp = data[j];
                data[j] = data[j + 2];
                data[j + 2] = tmp;
            }
        }

        fclose(file);
        return data;
    }
};
