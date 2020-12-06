#pragma once

#include "profile.cpp"

class Game
{

public:
    Profile profile;

	bool start()
	{
		cout << "Starting game.";

		return 1;
	}

	bool stop()
	{
        return 1;

	}

	explicit Game(const Profile &profile)
	: profile(profile)
	{

	};
};