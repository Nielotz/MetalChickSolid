#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <string>

namespace PATH
{
	namespace HERO
	{
		namespace TEXTURES
		{
			namespace WARRIOR
			{
				const static std::string FRONT = "textures\\mobs\\hero\\test_hero.png";
				const static std::string LEFT = "textures\\mobs\\hero\\test_hero.png";
				const static std::string RIGHT = "textures\\mobs\\hero\\test_hero.png";
				const static std::string BACK = "textures\\mobs\\hero\\test_hero.png";
			};
		}
	};

	namespace MAP
	{
		namespace TEXTURES
		{
			const static std::string START = "textures\\maps\\test_map.tga";

		}
	}
};

struct CONSTS
{
	const static sf::Vector2u GAME_SCREEN_RATIO;
	const static sf::Vector2u SCREEN_SIZE;
	const static sf::Vector2u GAME_WINNDOW_SIZE;

	// Scales everything to appear same on every screen.
	const static long double SCALE;

	const static uint16_t TILE_SIZE_ON_TEXTURE_MAP; // Pixels.
	// Tile size in game.
	const static uint16_t TILE_SIZE; // Pixels.

	// In tiles. 
	const static sf::Vector2u PLAYER_VIEW_RANGE;
};



