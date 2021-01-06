#include <SFML/Graphics.hpp>

#include <iostream>

#include "../headers/graphic.hpp"
#include "../headers/consts.hpp"


Graphic::Graphic()
{
	this->window = std::make_unique<sf::RenderWindow>(
		sf::VideoMode(CONSTS::GAME_WINNDOW_SIZE.x, CONSTS::GAME_WINNDOW_SIZE.y), "Metal chick solid");

	map_view.setSize(sf::Vector2f(
		float(CONSTS::PLAYER_VIEW_RANGE.x * CONSTS::TILE_SIZE), 
		float(CONSTS::PLAYER_VIEW_RANGE.y * CONSTS::TILE_SIZE)
	));

	map_view.setCenter(sf::Vector2f(
		float(CONSTS::PLAYER_VIEW_RANGE.x * ((CONSTS::TILE_SIZE + 1) / 2)),
		float(CONSTS::PLAYER_VIEW_RANGE.y * ((CONSTS::TILE_SIZE + 1) / 2))
	));

	// setViewport scales view!
	this->map_view.setViewport(sf::FloatRect(0.f, 0.f, 10.f/16.f, 1.f));

}

void Graphic::load_level(Map& map)
{
	std::clog << "Loading map: " << map.name << std::endl;
	this->map = map;
	this->map.sprite.setScale(float(CONSTS::SCALE), float(CONSTS::SCALE));
}

void Graphic::update()
{
	draw_map();
}

void Graphic::move_hero(const Direction& direction)
{
	bool can = true;
	if (direction == Direction::LEFT && can)
		map_view.move(float(-CONSTS::TILE_SIZE), 0);
	else if (direction == Direction::RIGHT && can)
		map_view.move(float(CONSTS::TILE_SIZE), 0);
	else if (direction == Direction::TOP && can)
		map_view.move(0, float(-CONSTS::TILE_SIZE));
	else if (can) // BOTTOM
		map_view.move(0, float(CONSTS::TILE_SIZE));
}

void Graphic::draw_map()
{
	this->window->setView(map_view);
	window->draw(map.sprite);

}

void Graphic::draw_hero(Position &hero_position)
{

}

void Graphic::increase_lvl()
{

}


