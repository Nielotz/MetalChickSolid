#pragma once

#include "profile.cpp"

class Game
{

public:
	bool start()
	{
		cout << "Starting game.";

		return 1;
	}

	bool stop()
	{
        return 1;

	}

	Game(const Profile &profile)
	{

	};
};