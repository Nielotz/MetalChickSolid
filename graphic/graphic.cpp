#include <SFML/Graphics.hpp>

#include <iostream>

#include "../headers/graphic.hpp"
#include "../headers/consts.hpp"


void Graphic::update_hero_animation_frame()
{
	std::chrono::duration<double> time_diff = std::chrono::steady_clock::now() - time_point_of_last_change_animation_frame;

	if (time_diff.count() >= MOVE_ANIMATION_FRAME_TIME)
	{
		time_point_of_last_change_animation_frame = std::chrono::steady_clock::now();
		next_hero_animation_frame();
		update_hero_texture_position();
	}
}

void Graphic::update_hero_step()
{
	std::chrono::duration<double> time_diff = std::chrono::steady_clock::now() - time_point_of_last_move_hero;

	if (move_step == 0 || time_diff.count() >= MOVE_STEP_FRAME_TIME)
	{
		if (MOVE_STEPS == move_step)
		{
			if (distance_left_to_move > 0.0000001)
				update_hero_texture_position();
			is_hero_moving = false;
			hero_animation_frame = 0;
		}
		else
		{
			distance_left_to_move -= float(distance_left_to_move) / float((MOVE_STEPS - move_step++));
			// std::cout << "UPDATED ANIMATION MOVE STEP TO: " << int(move_step) << std::endl;

			update_hero_texture_position();
		}

		time_point_of_last_move_hero = std::chrono::steady_clock::now();
	}
}

Enemy* Graphic::check_click_intersect_enemy(sf::Vector2i& mouse_click_pos)
{
	typedef std::pair<Enemy* const, std::pair<sf::Sprite, sf::Texture>> lel;

	for (lel& pair_enemy_with_sprite_texture : map_enemy_sprites_with_texture)
		if (pair_enemy_with_sprite_texture.second.first.getGlobalBounds().contains(sf::Vector2f{ mouse_click_pos }))
			return pair_enemy_with_sprite_texture.first;
	return nullptr;
}

ARENA_BUTTON Graphic::check_arena_button_clicked(sf::Vector2i& mouse_click_pos)
{
	//std::cout << mouse_click_pos.x << " " << mouse_click_pos.y << " " << ATTACK_BUTTON.left << " " << ATTACK_BUTTON.top << std::endl;
	if (ATTACK_BUTTON.contains(mouse_click_pos))
		return ARENA_BUTTON::ATTACK;
	else if (MAGIC_BUTTON.contains(mouse_click_pos))
		return ARENA_BUTTON::MAGIC;
	else if (QUICK_HEAL_BUTTON.contains(mouse_click_pos))
		return ARENA_BUTTON::QUICK_HEAL;
	else if (DEFENCE_BUTTON.contains(mouse_click_pos))
		return ARENA_BUTTON::DEFENCE;
	else if (RUN_AWAY_BUTTON.contains(mouse_click_pos))
		return ARENA_BUTTON::RUN_AWAY;
	else if (SAVE_FIGHT_BUTTON.contains(mouse_click_pos))
		return ARENA_BUTTON::SAVE_FIGHT;

	return ARENA_BUTTON::NONE;
}

Graphic::Graphic(Hero& hero)
	:MOVE_STEP_FRAME_TIME(1. / (MOVE_STEPS * hero.move_speed))
{
	// Reset times.
	time_point_of_last_change_animation_frame = time_point_of_last_move_hero
		= std::chrono::steady_clock::now();

	this->hero = &hero;

	window = std::make_unique<sf::RenderWindow>(
		sf::VideoMode(CONSTS::GAME_WINDOW_SIZE.x, CONSTS::GAME_WINDOW_SIZE.y),
		"Metal chick solid",
		sf::Style::Close
		);

	window->setFramerateLimit(60);

	set_views();

	load_UIs();

	// Set hero in arena.
	// std::string texture_path = PATH::HERO::TEXTURES::WARRIOR_ARENA;

	// load_arena_hero_texture(texture_path);
	// set_arena_hero_position((Position&)Position(3, 6));
	// set_arena_hero_size(8);

	load_hero_textures(PATH::HERO::TEXTURES::warrior);

	load_arena_background((std::string&)PATH::ARENA::TEXTURES::FORREST);

	std::string tut_path = PATH::TUTORIAL::TEXTURES::TUT;

	tutorial.load_tutorial_texture(tut_path);
}

void Graphic::load_level(Map& map)
{
	this->map = map;
	this->map.sprite.setScale(float(CONSTS::SCALE), float(CONSTS::SCALE));

	this->map.sprite.setPosition(0, 0); // To be read from map_data.
}

void Graphic::load_enemy_texture(Enemy& enemy, std::string& path)
{
	map_enemy_sprites_with_texture.insert({ &enemy, { sf::Sprite(), sf::Texture()} });

	sf::Sprite& sprite = map_enemy_sprites_with_texture.at(&enemy).first;
	sf::Texture& texture = map_enemy_sprites_with_texture.at(&enemy).second;

	if (!texture.loadFromFile(path))
		throw std::runtime_error("Cannot load " + path);

	texture.setSmooth(true);

	sprite.setTexture(texture);
}

void Graphic::remove_enemy_from_map(Enemy& enemy)
{
	map_enemy_sprites_with_texture.erase(&enemy);
}

void Graphic::remove_enemies_from_map()
{
	map_enemy_sprites_with_texture.clear();
}

void Graphic::load_tut_texture(const std::string& path)
{
	//na razie si� poddaj� ale jeszcze do tego wr�c�
}

void Graphic::load_arena_hero_texture(std::string& path)
{
	arena_hero_sprite_with_texture = { sf::Sprite(), sf::Texture() };

	sf::Sprite& sprite = arena_hero_sprite_with_texture.first;
	sf::Texture& texture = arena_hero_sprite_with_texture.second;

	if (!texture.loadFromFile(path))
		throw std::runtime_error("Cannot load " + path);

	texture.setSmooth(true);

	sprite.setTexture(texture);
}


void Graphic::load_arena_enemy_texture(Enemy& enemy, std::string& path)
{
	arena_enemy_sprites_with_texture.insert({ &enemy, { sf::Sprite(), sf::Texture()} });

	sf::Sprite& sprite = arena_enemy_sprites_with_texture.at(&enemy).first;
	sf::Texture& texture = arena_enemy_sprites_with_texture.at(&enemy).second;

	if (!texture.loadFromFile(path))
		throw std::runtime_error("Cannot load " + path);

	texture.setSmooth(true);

	sprite.setTexture(texture);
}

void Graphic::load_hero_textures(const std::unordered_map<Direction, std::vector<std::string>> paths_to_hero_textures)
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

			sprite.setPosition(position_to_display_position(hero->position, sprite));

			hero_sprites_with_texture.insert(
				{ direction, sprite_texture_vector_of_pairs{ sprite_texture_pair {sprite, texture} } }
			);

			texture_id++;
		}
	}
}

void Graphic::load_UIs()
{
	ui.load_panels_textures(
		(const std::string&)PATH::PANEL::TEXTURES::WALK_UI_RIGHT_PANEL,
		(const std::string&)PATH::PANEL::TEXTURES::ARENA_UI_RIGHT_PANEL
	);
}

void Graphic::load_tutorial()
{
	const std::string& path = PATH::TUTORIAL::TEXTURES::TUT;
	tutorial.load_tutorial_texture(path);
}

void Graphic::set_hero_position(Position& position)
{
	hero_looking_direction = Direction::BOTTOM;

	sf::Sprite& hero_sprite = hero_sprites_with_texture.at(hero_looking_direction)[hero_animation_frame].first;
	hero_sprite.setPosition(position_to_display_position(position, hero_sprite));
}

void Graphic::draw_enemies()
{
	window->setView(main_view);

	for (std::pair<Enemy* const, std::pair<sf::Sprite, sf::Texture>>& pair_id_data : map_enemy_sprites_with_texture)
		if (true)
			window->draw(pair_id_data.second.first);

}

void Graphic::draw_hero()
{
	typedef std::pair<sf::Sprite, sf::Texture> sprite_texture_pair;
	typedef std::vector<sprite_texture_pair> sprite_texture_vector_of_pairs;

	// Directional textures.
	sprite_texture_vector_of_pairs& animation_frames = hero_sprites_with_texture.at(hero_looking_direction);

	sf::Sprite& hero_sprite = animation_frames[hero_animation_frame].first;
	update_hero_texture_position();

	window->setView(main_view);
	window->draw(hero_sprite);
}

void Graphic::set_enemy_position(Enemy& enemy, Position position)
{
	sf::Sprite& entity_sprite = map_enemy_sprites_with_texture.at(&enemy).first;

	entity_sprite.setPosition(position_to_display_position(position, entity_sprite));
}

void Graphic::set_arena_enemy_position(Enemy& enemy, Position& position)
{
	sf::Sprite& entity_sprite = arena_enemy_sprites_with_texture.at(&enemy).first;

	entity_sprite.setPosition(position_to_display_position(position, entity_sprite));
}

void Graphic::set_arena_hero_position(Position& position)
{
	sf::Sprite& entity_sprite = arena_hero_sprite_with_texture.first;

	entity_sprite.setPosition(position_to_display_position(position, entity_sprite));
}

void Graphic::set_enemy_size(Enemy& enemy, uint8_t height)
{
	sf::Texture& entity_texture = map_enemy_sprites_with_texture.at(&enemy).second;
	sf::Sprite& entity_sprite = map_enemy_sprites_with_texture.at(&enemy).first;

	float scale = float(CONSTS::TILE_SIZE * height) / float(entity_texture.getSize().y);

	entity_sprite.setScale(sf::Vector2f{ scale, scale });
}

void Graphic::set_arena_enemy_size(Enemy& enemy, uint8_t height)
{
	sf::Texture& entity_texture = arena_enemy_sprites_with_texture.at(&enemy).second;
	sf::Sprite& entity_sprite = arena_enemy_sprites_with_texture.at(&enemy).first;

	float scale = float(CONSTS::TILE_SIZE * height) / float(entity_texture.getSize().y);

	entity_sprite.setScale(sf::Vector2f{ scale, scale });
}

void Graphic::set_arena_hero_size(uint8_t height)
{
	sf::Texture& entity_texture = arena_hero_sprite_with_texture.second;
	sf::Sprite& entity_sprite = arena_hero_sprite_with_texture.first;

	float scale = float(CONSTS::TILE_SIZE * height) / float(entity_texture.getSize().y);

	entity_sprite.setScale(sf::Vector2f{ scale, scale });
}

void Graphic::draw_UI()
{
	window->setView(side_panel_view);
	ui.draw(*(window.get()), display_ui_type);
}

void Graphic::draw_tutorial()
{
	tutorial.draw(*(window.get()));
}

void Graphic::draw_arena_background()
{
	window->setView(main_view);
	window->draw(arena_sprite_texture_pair.first);
}

void Graphic::load_arena_background(std::string& path)
{
	sf::Sprite& sprite = arena_sprite_texture_pair.first;
	sf::Texture& texture = arena_sprite_texture_pair.second;

	if (!texture.loadFromFile(path))
		throw std::runtime_error("Cannot load " + path);

	texture.setSmooth(true);

	sprite.setTexture(texture);

	float scale = std::min<float>(
		(float)((float)main_view.getSize().x / texture.getSize().x),
		(float)((float)main_view.getSize().y / texture.getSize().y));

	sprite.setScale(sf::Vector2f{ scale, scale });
	sprite.setPosition(0, 0);
}

void Graphic::update_walk_screen()
{
	update_hero_on_map();

	draw_UI();

	draw_map();
	draw_enemies();
	draw_hero();
}

void Graphic::update_arena_screen()
{
	window->clear(sf::Color::Red);

	draw_arena_background();
	draw_UI();
	draw_enemies_on_fight_arena();
	//draw_hero_on_fight_arena();
}

void Graphic::draw_enemies_on_fight_arena()
{
	window->setView(main_view);

	for (auto& enemy : entities_on_arena)
		window->draw(arena_enemy_sprites_with_texture.at(enemy).first);
}

void Graphic::draw_hero_on_fight_arena()
{
	window->setView(main_view);
	window->draw(arena_hero_sprite_with_texture.first);
}

void Graphic::update()
{
	if (display_screen_type == DISPLAY_SCREEN_TYPE::WALK)
		update_walk_screen();
	else // ARENA
		update_arena_screen();
}

void Graphic::set_views()
{
	set_main_view();
	set_side_view();
}

void Graphic::set_main_view()
{
	// In px.
	float view_size_x = float(CONSTS::PLAYER_VIEW_RANGE.x * CONSTS::TILE_SIZE);
	float view_size_y = float(CONSTS::PLAYER_VIEW_RANGE.y * CONSTS::TILE_SIZE);

	float view_position_x = float((CONSTS::PLAYER_VIEW_RANGE.x) * CONSTS::TILE_SIZE) / 2.f;
	float view_position_y = float((CONSTS::PLAYER_VIEW_RANGE.y) * CONSTS::TILE_SIZE) / 2.f;

	main_view.setSize(view_size_x, view_size_y);
	main_view.setCenter(view_position_x, view_position_y);

	// setViewport scales view!
	main_view.setViewport(sf::FloatRect(0.f, 0.f, 20.f / 26.f, 1.f));
}

void Graphic::set_side_view()
{

	// In px.
	float view_size_x = float(6 * CONSTS::TILE_SIZE);
	float view_size_y = float(CONSTS::GAME_SCREEN_RATIO.y * double(CONSTS::TILE_SIZE));

	float view_position_x = float(6 * (CONSTS::TILE_SIZE)) / 2.f;
	float view_position_y = float((CONSTS::GAME_SCREEN_RATIO.y * double(CONSTS::TILE_SIZE)) / 2.);

	side_panel_view.setSize(view_size_x, view_size_y);
	side_panel_view.setCenter(view_position_x, view_position_y);

	// setViewport scales view!
	side_panel_view.setViewport(sf::FloatRect(float(20. / 26.), 0.f, float(6. / 26.), 1.f));
}

void Graphic::move_view(const Direction& direction)
{
	sf::Vector2f mv_center = main_view.getCenter();
	sf::Vector2f mv_half_size = { main_view.getSize().x / 2.f, main_view.getSize().y / 2.f };

	// Margin for float imprecision included.
	if (direction == Direction::LEFT
		&& mv_center.x + mv_half_size.x < map.sprite.getGlobalBounds().width)
		main_view.move(float(CONSTS::TILE_SIZE), 0);

	if (direction == Direction::RIGHT
		&& mv_center.x - mv_half_size.x > 3)
		main_view.move(float(-CONSTS::TILE_SIZE), 0);

	if (direction == Direction::TOP
		&& mv_center.y + mv_half_size.y < CONSTS::TILE_SIZE * map.tiles_number.y - 3)
		main_view.move(0, float(CONSTS::TILE_SIZE));

	if (direction == Direction::BOTTOM
		&& mv_center.y - mv_half_size.y > 3)
		main_view.move(0, float(-CONSTS::TILE_SIZE));
	std::cout << mv_center.y - mv_half_size.y << std::endl;
}

void Graphic::update_view()
{
	// Margin for float imprecision included.
	uint16_t distance_to_left_wall = -1;
	uint16_t distance_to_right_wall = -1;
	uint16_t distance_to_top_wall = -1;
	uint16_t distance_to_bottom_wall = -1;

	uint16_t tile_size = CONSTS::TILE_SIZE;

	sf::Vector2f mv_size = main_view.getSize();
	sf::Vector2f mv_center = main_view.getCenter();
	Position& hero_pos = hero->position;

	sf::Vector2f hero_pos_px = { float(hero_pos.x * tile_size) , float(hero_pos.y * tile_size) };
	sf::Vector2f mv_pos_px = { float(mv_center.x - mv_size.x / 2.f) , float(mv_center.y - mv_size.y / 2.f) };

	distance_to_left_wall = uint16_t((hero_pos_px.x - mv_pos_px.x) / tile_size);
	distance_to_right_wall = uint16_t((mv_size.x - (hero_pos_px.x - mv_pos_px.x)) / tile_size);
	distance_to_top_wall = uint16_t((hero_pos_px.y - (mv_center.y - mv_size.y / 2.f)) / tile_size);
	distance_to_bottom_wall = uint16_t((-(hero_pos_px.y - (mv_center.y + mv_size.y / 2.f)) / tile_size));

	if (distance_to_left_wall < CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER)
		move_view(Direction::RIGHT);
	if (distance_to_right_wall < CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER)
		move_view(Direction::LEFT);
	if (distance_to_top_wall < CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER)
		move_view(Direction::BOTTOM);
	if (distance_to_bottom_wall < CONSTS::MIN_PLAYER_DISTANCE_TO_BORDER)
		move_view(Direction::TOP);

	// std::cout << distance_to_left_wall << " " << distance_to_right_wall << " " << distance_to_top_wall << " " << distance_to_bottom_wall << " " << std::endl;
	// std::cout << hero->position.x << " " << hero->position.y << std::endl;
}

// Update the hero position on the map.
// Updates view.
void Graphic::update_hero_texture_position()
{
	sf::Sprite& hero_sprite = hero_sprites_with_texture.at(hero_looking_direction)[hero_animation_frame].first;

	sf::Vector2f hero_pos = position_to_display_position(hero->position, hero_sprite);

	sf::Vector2f new_pos(hero_pos);

	float distance_traveled = -distance_left_to_move;

	if (hero_looking_direction == Direction::LEFT)
		new_pos.x -= distance_traveled;
	else if (hero_looking_direction == Direction::RIGHT)
		new_pos.x += distance_traveled;
	else if (hero_looking_direction == Direction::TOP)
		new_pos.y -= distance_traveled;
	else // BOTTOM
		new_pos.y += distance_traveled;

	hero_sprite.setPosition(new_pos);

	// std::cout << "NEW HERO POS: " << new_pos.x << " " << new_pos.y << " " << std::endl;
}

void Graphic::next_hero_animation_frame()
{
	typedef std::pair<sf::Sprite, sf::Texture> sprite_texture_pair;
	typedef std::vector<sprite_texture_pair> sprite_texture_vector_of_pairs;

	// Directional textures.
	sprite_texture_vector_of_pairs& animation_frames = hero_sprites_with_texture.at(hero_looking_direction);

	if (animation_frames.size() <= ++hero_animation_frame)
		hero_animation_frame = 0;

	update_hero_texture_position();

	// std::cout << "UPDATED ANIMATION FRAME TO: " << int(hero_animation_frame) << std::endl;

}

void Graphic::move_hero(const Direction& direction)
{
	if (is_hero_moving)
		return;

	time_point_of_last_change_animation_frame = time_point_of_last_move_hero
		= std::chrono::steady_clock::now();

	hero_animation_frame = 0;
	move_step = 0;
	distance_left_to_move = CONSTS::TILE_SIZE;
	hero_looking_direction = direction;
	is_hero_moving = true;
}

void Graphic::draw_map()
{
	window->setView(main_view);
	window->draw(map.sprite);
}

void Graphic::update_hero_on_map()
{
	if (is_hero_moving)
	{
		update_hero_animation_frame();
		update_hero_step();

		update_view();
	}
}

void Graphic::display_arena(Enemy& enemy)
{
	display_ui_type = UI_TYPE::FIGHT;
	display_screen_type = DISPLAY_SCREEN_TYPE::ARENA;

	entities_on_arena.clear();
	entities_on_arena.push_back(&enemy);
}

void Graphic::display_map()
{
	display_screen_type = DISPLAY_SCREEN_TYPE::WALK;
}

sf::Vector2f Graphic::position_to_display_position(Position& position, sf::Sprite& entity_sprite)
{
	return sf::Vector2f(
		float(position.x * CONSTS::TILE_SIZE),
		float(position.y * CONSTS::TILE_SIZE - (uint16_t(entity_sprite.getGlobalBounds().height) % CONSTS::TILE_SIZE)));
}
