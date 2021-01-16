#pragma once
#include <SFML/Graphics.hpp>

#include <memory>
#include <unordered_map>
#include <vector>
#include <chrono>

#include "map.hpp"
#include "hero.hpp"
#include "ui.hpp"
#include "tuts.hpp"
#include "enemy.hpp"


enum class DISPLAY_SCREEN_TYPE : uint8_t
{
    ARENA = 0,
    WALK = 1
};

class Graphic
{ 
    DISPLAY_SCREEN_TYPE display_screen_type = DISPLAY_SCREEN_TYPE::WALK;

    void set_views();
    void set_main_view();
    void set_side_view();
    TutorialGraphic tutorial;


	// Tries to move the view to keep the hero in the center of the view.
	// Moves only by 1 tile.
	void move_view(const Direction& direction);

    // Draw the map around hero (his render view).
    void draw_map();

    // Draw ui.
    void draw_UI();

    // Move into Arena class.

    void draw_arena_background();
    std::pair<sf::Sprite, sf::Texture> arena_sprite_texture_pair;

	// Keep textures and sprites in pairs (for each direction):
	//		Direction::LEFT: texture1, texture2, texture3...
	//		Direction::... texture1, texture2, texture3...
	//
	// Keep texture because sf::Sprite stores only reference to the texture.
	std::unordered_map<Direction, std::vector<std::pair<sf::Sprite, sf::Texture>>> hero_sprites_with_texture;

    // User Interface class.
    UI ui;

    // UI that is now displayed;
    UI_TYPE display_ui_type = UI_TYPE::WALK;

    // Convert position (tiles) to sf::Vector2f position (pixels).
    sf::Vector2f position_to_display_position(Position& position, sf::Sprite& entity_sprite);

    sf::View main_view;
    sf::View side_panel_view;

    Map map;
    Hero* hero;

    // id: <sprite, texture>
    std::unordered_map<Enemy*, std::pair<sf::Sprite, sf::Texture>> map_enemy_sprites_with_texture;

    // Move into arena class.
    std::unordered_map<Enemy*, std::pair<sf::Sprite, sf::Texture>> arena_enemy_sprites_with_texture;

    // Move into arena class.
    std::vector<Enemy*> entities_on_arena;

	std::chrono::steady_clock::time_point time_point_of_last_change_animation_frame;
	std::chrono::steady_clock::time_point time_point_of_last_move_hero;

	uint8_t hero_animation_frame = 0;
	uint8_t move_step;
	float distance_left_to_move;

	// Amount of small steps for man, but big for ants.
	const double MOVE_STEPS = 20;

	// Time between every step of hero move.
	const double MOVE_STEP_FRAME_TIME;

	// Unit: no idea, less than 6 = no move.
	const uint8_t MOVE_ANIMATION_PER_SECOND = 10;

	const double MOVE_ANIMATION_FRAME_TIME = 1. / MOVE_ANIMATION_PER_SECOND;

	void update_hero_texture_position();

	void next_hero_animation_frame();

	void update_hero_animation_frame();

	void update_hero_step();

    void update_walk_screen();

    void update_arena_screen();

    // Move into seperate fight arena class.
    void draw_enemies_on_fight_arena();

public:
    Direction hero_looking_direction = Direction::BOTTOM;

	bool is_hero_moving = false;
    
    Enemy* check_click_intersect_enemy(sf::Vector2i& mouse_click_pos);

	// Hero hero;
	std::unique_ptr<sf::RenderWindow> window;

    // Save hero for further use.
    Graphic(Hero& hero);

    // Update the view, to keep (when possible) hero at the center of the screen.
    // Relies on CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER.
    void update_view();

    // Update hero position, and animation frame.
    void update_hero_on_map();

    void load_arena_background(std::string& path);

    void display_arena(Enemy& enemy);

    void display_map();

    // Load level into the graphic.
    //
    // \param map: Map that will be displayed on the screen.
    // 
    void load_level(Map& map);

    void load_enemy_texture(Enemy& enemy, std::string& path);
    
    void remove_enemy_from_map(Enemy& enemy);

    // Move into arena class.
    void load_arena_enemy_texture(Enemy& enemy, std::string& path);

    void load_hero_textures(const std::unordered_map<Direction, std::vector<std::string>> paths_to_hero_textures
    );

    // Take texture from CONSTS::
    void load_UIs();

    void load_tutorial();

    void set_hero_position(Position& position);

    void set_enemy_position(Enemy& enemy, Position& position);

    void set_arena_enemy_position(Enemy& enemy, Position& position);

    // Height in tiles, width automaticly adjusts.
    void set_enemy_size(Enemy& enemy, uint8_t height);

    void set_arena_enemy_size(Enemy& enemy, uint8_t height);

    // Draw enemies at theirs positions.
    void draw_enemies();

    // Draw hero at its position.
    void draw_hero();

    void draw_ui();

    void draw_tutorial();

    // Draw fireworks and update stats.
    void increase_lvl();

    // Updates screen.
    void update();

    void move_hero(const Direction& direction);

    void load_tut_texture(const std::string& path);
};
