#include <SFML/Graphics.hpp>

#include <iostream>

#include "../headers/graphic.hpp"
#include "../headers/consts.hpp"


Graphic::Graphic(Hero& hero)
{
	this->hero = std::make_shared<Hero>(hero);
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
	this->map_view.setViewport(sf::FloatRect(0.f, 0.f, 10.f / 16.f, 1.f));

}

void Graphic::load_level(Map& map)
{
	this->map = map;
	this->map.sprite.setScale(float(CONSTS::SCALE), float(CONSTS::SCALE));
}

void Graphic::load_texture(Entity& entity, std::string& path)
{
	sf::Texture texture;
	if (!texture.loadFromFile(path))
		throw std::runtime_error("Cannot load " + path);

	texture.setSmooth(true);

	sf::Sprite sprite(texture);
	sprite.setPosition(tile_position_to_vector2f_position(entity.position));

	entity_sprites.insert(std::pair<uint64_t, sf::Sprite>(entity.id, sprite));
}

void Graphic::load_hero_textures(Hero& entity,
	const std::string& path_to_hero_left,
	const std::string& path_to_hero_right,
	const std::string& path_to_hero_top,
	const std::string& path_to_hero_bottom)
{
	hero_textures.resize(4);
	hero_sprites.resize(4);

	uint8_t i = 0;
	for (auto& path : { path_to_hero_left , path_to_hero_right, path_to_hero_top, path_to_hero_bottom })
	{
		if (!hero_textures[i].loadFromFile(path))
			throw std::runtime_error("Cannot load " + path);

		hero_textures[i].setSmooth(true);

		hero_sprites[i].setTexture(hero_textures[i]);
		hero_sprites[i].setPosition(tile_position_to_vector2f_position(entity.position));
		
		i++;
	}
}

void Graphic::draw_entities()
{
	for (auto& texture : entity_sprites)
		if (true)
			window->draw(entity_sprites[1]);
}

void Graphic::draw_hero()
{
	hero_sprites[uint8_t(hero_direction)].setPosition(tile_position_to_vector2f_position(hero->position));
	window->draw(hero_sprites[uint8_t(hero_direction)]);
}

void Graphic::update()
{
	draw_map();
	//draw_entities();
	draw_hero();
}

void Graphic::move_view(const Direction& direction)
{
	// It is not working but it is working no idea why, just accept it or rewrite:
	// center of the view + half of the view size.

	// Margin for float error included.
	if (direction == Direction::LEFT
		&& this->map_view.getCenter().x + this->map_view.getSize().x / 2 < CONSTS::TILE_SIZE * map.tiles_number.x - 3)
		map_view.move(float(CONSTS::TILE_SIZE), 0);

	else if (direction == Direction::RIGHT
		&& this->map_view.getCenter().x - this->map_view.getSize().x / 2 > 3)
		map_view.move(float(-CONSTS::TILE_SIZE), 0);

	else if (direction == Direction::TOP
		&& this->map_view.getCenter().y + this->map_view.getSize().y / 2 < CONSTS::TILE_SIZE * map.tiles_number.y - 3)
		map_view.move(0, float(CONSTS::TILE_SIZE));

	else if (direction == Direction::BOTTOM
		&& this->map_view.getCenter().y - this->map_view.getSize().y / 2 > 3)
		map_view.move(0, float(-CONSTS::TILE_SIZE));
}

void Graphic::move_hero(const Direction& direction)
{
	if (direction == Direction::LEFT)
	{
		hero->position.x--;
		if (true)
			move_view(Direction::RIGHT);
	}
	else if (direction == Direction::RIGHT)
	{
		hero->position.x++;

		if (true)
			move_view(Direction::LEFT);
	}
	else if (direction == Direction::TOP)
	{
		hero->position.y--;
		if (true)
			move_view(Direction::BOTTOM);
	}
	else // BOTTOM
	{
		hero->position.y++;

		if (true)
			move_view(Direction::TOP);
	}
}

void Graphic::draw_map()
{
	this->window->setView(map_view);
	window->draw(map.sprite);
}

sf::Vector2f Graphic::tile_position_to_vector2f_position(Position& position)
{
	return sf::Vector2f(float(position.x * CONSTS::TILE_SIZE), float(position.y * CONSTS::TILE_SIZE));
}


void Graphic::increase_lvl()
{

}


