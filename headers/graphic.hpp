#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "map.hpp"
#include "hero.hpp"
#include <unordered_map>



class Graphic
{
	// Try to keep hero in the center of the view.
	void move_view(const Direction& direction);

	// Draw the map around hero (his render view).
	void draw_map();

	Direction hero_direction = Direction::BOTTOM;

	// sf::Sprite stores only reference to the texture.
	std::vector<sf::Texture> hero_textures;
	std::vector<sf::Sprite> hero_sprites;

	sf::Vector2f tile_position_to_vector2f_position(Position& position);
	
	sf::View map_view;

	Map map;
	std::shared_ptr<Hero> hero;
	std::unordered_map<uint64_t, sf::Sprite> entity_sprites;

public:
	// Hero hero;
	std::unique_ptr<sf::RenderWindow> window;

	// Save hero for further use.
	Graphic(Hero& hero);

	// Load level into the graphic.
	//
	// \param map: Map that will be displayed on the screen.
	// 
	void load_level(Map& map);

	void load_texture(Entity& entity, std::string& path);

	void load_hero_textures(Hero& entity, 
		const std::string& path_to_hero_left, 
		const std::string& path_to_hero_right,
		const std::string& path_to_hero_top,
		const std::string& path_to_hero_bottom
		);

	// Draw entities at theirs positions.
	void draw_entities();

	// Draw hero at its position.
	void draw_hero();

	// Draw fireworks and update stats.
	void increase_lvl();

	// Updates screen.
	void update();

	void move_hero(const Direction& direction);
};
