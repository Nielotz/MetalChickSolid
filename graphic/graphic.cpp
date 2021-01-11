#include <SFML/Graphics.hpp>

#include <iostream>

#include "../headers/graphic.hpp"
#include "../headers/consts.hpp"


Graphic::Graphic(Hero& hero)
{
	this->hero = &hero;
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

	Position position(0, 0);
	this->map.sprite.setPosition( position_to_display_position(position, map.sprite) ); // To be read from map_data.
}

void Graphic::load_texture(Entity& entity, std::string& path)
{
	sf::Texture texture;
	if (!texture.loadFromFile(path))
		throw std::runtime_error("Cannot load " + path);

	texture.setSmooth(true);

	sf::Sprite sprite(texture);

	entity_sprites.insert(std::pair<uint64_t, sf::Sprite>(entity.id, sprite));
}

void Graphic::load_hero_textures(Hero& entity,
	const std::unordered_map<Direction, std::vector<std::string>> paths_to_hero_textures)
{
	typedef std::pair<sf::Sprite, sf::Texture> sprite_texture_pair;
	typedef std::vector<sprite_texture_pair> sprite_texture_vector_of_pairs;
	hero_sprites_with_texture.clear();

	for (const auto& direction : { Direction::LEFT, Direction::RIGHT, Direction::BOTTOM, Direction::TOP })
	{
		hero_sprites_with_texture.insert({ direction, {} });
		sprite_texture_vector_of_pairs& directional_hero_sprites_with_texture = hero_sprites_with_texture.at(direction);

		directional_hero_sprites_with_texture.resize(paths_to_hero_textures.at(direction).size());

		uint16_t texture_id = 0;
		for (const std::string& path : paths_to_hero_textures.at(direction))
		{
			directional_hero_sprites_with_texture[texture_id] = sprite_texture_pair{ sf::Sprite(), sf::Texture() };

			sf::Sprite& sprite = directional_hero_sprites_with_texture[texture_id].first;
			sf::Texture& texture = directional_hero_sprites_with_texture[texture_id].second;

			if (!texture.loadFromFile(path))
				throw std::runtime_error("Cannot load " + path);

			texture.setSmooth(true);

			sprite.setTexture(texture);
			float scale = float(CONSTS::TILE_SIZE) / float(texture.getSize().x);
			sprite.setScale(sf::Vector2f{ scale, scale });

			hero_sprites_with_texture.insert(
				{ direction, sprite_texture_vector_of_pairs{ sprite_texture_pair {sprite, texture} } }
			);

			texture_id++;
		}
	}
}

void Graphic::set_hero_position(Position& position)
{
	sf::Sprite& hero_sprite = hero_sprites_with_texture.at(hero->looking_direction)[hero->animation_frame].first;
	hero_sprite.setPosition(position_to_display_position(hero->position, hero_sprite));
}

void Graphic::draw_entities()
{
	for (auto& texture : entity_sprites)
		if (true)
			window->draw(entity_sprites[1]);
}

void Graphic::draw_hero()
{
	sf::Sprite& hero_sprite = hero_sprites_with_texture.at(hero->looking_direction)[hero->animation_frame].first;
	window->draw(hero_sprite);
}

void Graphic::update()
{
	draw_map();
	//draw_entities();
	draw_hero();
}

void Graphic::move_view(const Direction& direction)
{
	// Margin for float imprecision included.
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
	sf::Sprite& hero_sprite = hero_sprites_with_texture.at(hero->looking_direction)[hero->animation_frame].first;

	if (direction == Direction::LEFT)
	{
		hero_sprite.move(float(-CONSTS::TILE_SIZE), 0);

	}
	else if (direction == Direction::RIGHT)
	{
		hero_sprite.move(float(CONSTS::TILE_SIZE), 0);

	}
	else if (direction == Direction::TOP)
	{
		hero_sprite.move(0, float(-CONSTS::TILE_SIZE));

	}
	else // BOTTOM
	{
		hero_sprite.move(0, float(CONSTS::TILE_SIZE));

	}

	update_view();
}

void Graphic::draw_map()
{
	this->window->setView(map_view);
	window->draw(map.sprite);
}

void Graphic::update_view()
{
	Direction move_direction = Direction::LEFT;
	//Direction move_direction = Direction::RIGHT;
	//Direction move_direction = Direction::TOP;
	//Direction move_direction = Direction::BOTTOM;

	// Margin for float imprecision included.
	float distance_to_left_wall = -1;
	float distance_to_right_wall = -1;
	float distance_to_top_wall = -1;
	float distance_to_bottom_wall = -1;

	distance_to_left_wall = (hero->position.x * CONSTS::TILE_SIZE + 3 - (this->map_view.getCenter().x - this->map_view.getSize().x / 2))
		/ CONSTS::TILE_SIZE;

	distance_to_right_wall = (-(hero->position.x * CONSTS::TILE_SIZE - 3 - (this->map_view.getCenter().x + this->map_view.getSize().x / 2))
		/ CONSTS::TILE_SIZE)
		- 1; // Recompense for hero size.

	distance_to_top_wall = (hero->position.y * CONSTS::TILE_SIZE + 3 - (this->map_view.getCenter().y - this->map_view.getSize().y / 2))
		/ CONSTS::TILE_SIZE;

	distance_to_bottom_wall = (-(hero->position.y * CONSTS::TILE_SIZE - 3 - (this->map_view.getCenter().y + this->map_view.getSize().y / 2))
		/ CONSTS::TILE_SIZE)
		- 1; // Recompense for hero size.

	if (distance_to_left_wall < CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER)
		move_view(Direction::RIGHT);
	else if (distance_to_right_wall < CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER)
		move_view(Direction::LEFT);
	else if (distance_to_top_wall < CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER)
		move_view(Direction::BOTTOM);
	else if (distance_to_bottom_wall < CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER)
		move_view(Direction::TOP);


	std::cout << distance_to_left_wall << " " << distance_to_right_wall << " " << distance_to_top_wall << " " << distance_to_bottom_wall << " " << std::endl;
	std::cout << hero->position.x << " " << hero->position.y << std::endl;

}

sf::Vector2f Graphic::position_to_display_position(Position& position, sf::Sprite& entity_sprite)
{
	return sf::Vector2f(
		float(position.x * CONSTS::TILE_SIZE),
		float(position.y * CONSTS::TILE_SIZE - uint16_t(entity_sprite.getGlobalBounds().height) % CONSTS::TILE_SIZE));
}


void Graphic::increase_lvl()
{

}


