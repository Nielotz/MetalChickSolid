#pragma once
#include <SFML/Graphics.hpp>

#include <memory>
#include <unordered_map>
#include <vector>


#include "map.hpp"
#include "hero.hpp"



class Graphic
{
	// Try to keep hero in the center of the view.
	void move_view(const Direction& direction);

	// Draw the map around hero (his render view).
	void draw_map();

	Direction hero_direction = Direction::BOTTOM;

	// Keep textures and sprites in pairs (for each direction):
	//		Direction::LEFT: texture1, texture2, texture3...
	//		Direction::... texture1, texture2, texture3...
	//
	// Keep texture because sf::Sprite stores only reference to the texture.
	std::unordered_map<Direction, std::vector<std::pair<sf::Sprite, sf::Texture>>> hero_sprites_with_texture;

	sf::Vector2f entity_position_to_vector2f_display_position(Position& position, sf::Sprite& entity_sprite);

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
		const std::unordered_map<Direction, std::vector<std::string>> paths_to_hero_textures
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
