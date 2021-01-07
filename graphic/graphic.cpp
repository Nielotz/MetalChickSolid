#include <SFML/Graphics.hpp>

#include <iostream>

#include "../headers/graphic.hpp"
#include "../headers/consts.hpp"


Graphic::Graphic()
{
	this->window = std::make_unique<sf::RenderWindow>(
		sf::VideoMode(CONSTS::GAME_WINDOW_SIZE.x, CONSTS::GAME_WINDOW_SIZE.y), "Metal chick solid");

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

bool Graphic::can_view_move(const Direction& direction)
{
	// It is not working but it is working no idea why, just accept it or rewrite:
	// center of the view + half of the view size.

	// With margin for float error.
	if (direction == Direction::LEFT 
		&& this->map_view.getCenter().x * 2 < CONSTS::TILE_SIZE * map.tiles_number.x + 81)
		return true;
	else if (direction == Direction::RIGHT 
		&& this->map_view.getCenter().x * 2 > CONSTS::TILE_SIZE * CONSTS::PLAYER_VIEW_RANGE.x + 3)
		return true;
	else if (direction == Direction::TOP 
		&& this->map_view.getCenter().y * 2 < CONSTS::TILE_SIZE * map.tiles_number.y - 3)
		return true;
	else if (direction == Direction::BOTTOM 
		&& this->map_view.getCenter().y * 2 > CONSTS::TILE_SIZE * CONSTS::PLAYER_VIEW_RANGE.y + 3)
		return true;
	return false;
}

void Graphic::move_hero(const Direction& direction)
{
	if (direction == Direction::LEFT)
	{
		if (can_view_move(Direction::RIGHT))
			map_view.move(float(-CONSTS::TILE_SIZE), 0);
	}
	else if (direction == Direction::RIGHT)
	{
		if (can_view_move(Direction::LEFT))
			map_view.move(float(CONSTS::TILE_SIZE), 0);
	}
	else if (direction == Direction::TOP)
	{
		if (can_view_move(Direction::BOTTOM))
			map_view.move(0, float(-CONSTS::TILE_SIZE));
	}
	else 
	{
		if (can_view_move(Direction::TOP)) // BOTTOM
			map_view.move(0, float(CONSTS::TILE_SIZE));
	}
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


