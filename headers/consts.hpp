#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace CONSTS
{
	const sf::Vector2u SCREEN_SIZE = { sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };
	const sf::Vector2u GAME_WINNDOW_SIZE = { 1200, 900 };

	// Scales everything to appear same on every screen.
	const float SCALE = std::min(SCREEN_SIZE.x, SCREEN_SIZE.y) / 1080.;

	const uint16_t TILE_SIZE_ON_TEXTURE_MAP = 80; // Pixels.
	// Tile size in game.
	const uint16_t TILE_SIZE = uint16_t(TILE_SIZE_ON_TEXTURE_MAP * SCALE); // Pixels.

	const sf::Vector2u PLAYER_VIEW_RANGE = {10, 9};
};
