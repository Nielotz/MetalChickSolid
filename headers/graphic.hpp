#pragma once
#include <SFML/Graphics.hpp>

#include <memory>
#include <unordered_map>
#include <vector>
#include <chrono>


#include "map.hpp"
#include "hero.hpp"



class Graphic
{
	// Tries to move the view to keep the hero in the center of the view.
	// Moves only by 1 tile.
	void move_view(const Direction& direction);

	// Draw the map around hero (his render view).
	void draw_map();

	// Update the view, to keep (when possible) hero at the center of the screen.
	// Relies on CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER.
	void update_view();

	// Keep textures and sprites in pairs (for each direction):
	//		Direction::LEFT: texture1, texture2, texture3...
	//		Direction::... texture1, texture2, texture3...
	//
	// Keep texture because sf::Sprite stores only reference to the texture.
	std::unordered_map<Direction, std::vector<std::pair<sf::Sprite, sf::Texture>>> hero_sprites_with_texture;

	// Convert position (tiles) to sf::Vector2f position (pixels).
	sf::Vector2f position_to_display_position(Position& position, sf::Sprite& entity_sprite);

	sf::View map_view;

	Map map;
	Hero* hero;
	std::unordered_map<uint64_t, sf::Sprite> entity_sprites;

	Direction hero_looking_direction = Direction::BOTTOM;
	
	std::chrono::steady_clock::time_point time_point_of_last_change_animation_frame;
	std::chrono::steady_clock::time_point time_point_of_last_move_hero;

	uint8_t hero_animation_frame = 0;
	uint8_t move_step;
	float distance_left_to_move;

	// Amount of small steps for man, but big ants.
	const double MOVE_STEPS = 20;

	// Time between every step of hero move.
	const double MOVE_STEP_FRAME_TIME;

	// Unit: FPS.
	const uint8_t MOVE_ANIMATION_PER_SECOND = 6;

	const double MOVE_ANIMATION_FRAME_TIME = 1. / MOVE_ANIMATION_PER_SECOND;

	void move_hero_step(Direction& direction, float distance);

	void next_hero_animation_frame();

	void update_hero_animation_frame();

	void update_hero_position_on_map();

public:

	bool is_hero_moving = false;

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

	void set_hero_position(Position& position);

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
