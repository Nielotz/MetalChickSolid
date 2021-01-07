#include "../headers/consts.hpp"


const sf::Vector2u CONSTS::GAME_SCREEN_RATIO = { 16, 9 };
const uint16_t CONSTS::TILE_SIZE_ON_TEXTURE_MAP = 80;
const sf::Vector2u CONSTS::PLAYER_VIEW_RANGE = { 10, 9 };

const sf::Vector2u CONSTS::SCREEN_SIZE = {
	sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };

const long double CONSTS::SCALE = std::min<long double>(
	(long double)(CONSTS::SCREEN_SIZE.x / GAME_SCREEN_RATIO.x), 
	(long double)(CONSTS::SCREEN_SIZE.y / GAME_SCREEN_RATIO.y)) 
	/ (long double)(1920 / CONSTS::GAME_SCREEN_RATIO.x);

const uint16_t CONSTS::TILE_SIZE = uint16_t(CONSTS::TILE_SIZE_ON_TEXTURE_MAP * CONSTS::SCALE);
const sf::Vector2u CONSTS::GAME_WINDOW_SIZE = {
	(unsigned int)(CONSTS::TILE_SIZE * CONSTS::GAME_SCREEN_RATIO.x), 
	(unsigned int)(CONSTS::TILE_SIZE* CONSTS::GAME_SCREEN_RATIO.y) };



