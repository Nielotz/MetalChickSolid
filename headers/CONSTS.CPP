#include "consts.hpp"


const sf::Vector2u CONSTS::SCREEN_SIZE = {
	sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };
const sf::Vector2u CONSTS::GAME_WINNDOW_SIZE = { 1000, 1000 };
const float CONSTS::SCALE = std::min(CONSTS::SCREEN_SIZE.x, CONSTS::SCREEN_SIZE.y) / 1080.;
const uint16_t CONSTS::TILE_SIZE_ON_TEXTURE_MAP = 80;
const uint16_t CONSTS::TILE_SIZE = uint16_t(CONSTS::TILE_SIZE_ON_TEXTURE_MAP * CONSTS::SCALE);
const sf::Vector2u CONSTS::PLAYER_VIEW_RANGE = { 10, 9 };


