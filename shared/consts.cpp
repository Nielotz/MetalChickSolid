#include "../headers/consts.hpp"

const sf::Vector2u CONSTS::BASE_SCREEN_SIZE = { 26 * 80, 18 * 80 };

const sf::Vector2u CONSTS::GAME_SCREEN_RATIO = { 26, 18 };
const uint16_t CONSTS::TILE_SIZE_ON_TEXTURE_MAP = 80;
const sf::Vector2u CONSTS::PLAYER_VIEW_RANGE = { 20, 18 };

const uint8_t CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER = 2;


const sf::Vector2u CONSTS::SCREEN_SIZE = {
	sf::VideoMode::getDesktopMode().width,
	sf::VideoMode::getDesktopMode().height
};

const long double CONSTS::SCALE = std::min<long double>(
	(long double)((long double)CONSTS::SCREEN_SIZE.x / (long double)CONSTS::BASE_SCREEN_SIZE.x),
	(long double)((long double)CONSTS::SCREEN_SIZE.y / (long double)CONSTS::BASE_SCREEN_SIZE.y)) 
	- 0.05; // Make it to fit into the screen.

const uint16_t CONSTS::TILE_SIZE = uint16_t(CONSTS::TILE_SIZE_ON_TEXTURE_MAP * CONSTS::SCALE);

const sf::Vector2u CONSTS::GAME_WINDOW_SIZE = {
	(unsigned int)(CONSTS::TILE_SIZE * CONSTS::GAME_SCREEN_RATIO.x),
	(unsigned int)(CONSTS::TILE_SIZE * CONSTS::GAME_SCREEN_RATIO.y) };



