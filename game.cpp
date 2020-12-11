#pragma once

#include "profile.cpp"
#include "graphic.cpp"
#include "map.cpp"

class Game
{

public:
    const Profile *profile;
    Graphic graphic;
    shared_ptr<Map> map;

    void start()
	{
		cout << "Starting game.";
        // graphic.load_map(map);
	}

	void stop()
	{

	}

	explicit Game(const Profile *profile, const string &map_filename)
	: profile(profile)
	{
        map = make_shared<Map>(map_filename);
        //graphic = Graphic();
	};
};