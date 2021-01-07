#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

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

