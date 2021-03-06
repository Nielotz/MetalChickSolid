#include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>

#include "../headers/control.hpp"
#include "../headers/game.hpp"

#include <iostream>

bool Control::parse_move_events(sf::Event& event, Graphic& graphic, Game& game)
{
	bool parsed = true;
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::A)
		{
			game.move_hero(Direction::LEFT);
		}
		else if (event.key.code == sf::Keyboard::D)
		{
			game.move_hero(Direction::RIGHT);
		}
		else if (event.key.code == sf::Keyboard::W)
		{
			game.move_hero(Direction::TOP);
		}
		else if (event.key.code == sf::Keyboard::S)
		{
			game.move_hero(Direction::BOTTOM);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		game.move_hero(Direction::LEFT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		game.move_hero(Direction::RIGHT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		game.move_hero(Direction::TOP);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		game.move_hero(Direction::BOTTOM);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		game.start_tutorial();
	}
	else parsed = false;
	return parsed;
}

Enemy* Control::check_mouse_on_enemy_click(sf::Event& event, Graphic& graphic, Game& game)
{
	Enemy* clicked_enemy = nullptr;
	if (event.type == sf::Event::MouseButtonPressed)
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			auto mouse_click_pos = sf::Mouse::getPosition(*graphic.window.get());
			clicked_enemy = graphic.check_click_intersect_enemy(mouse_click_pos);
		}
	return clicked_enemy;
}

ARENA_BUTTON Control::check_arena_button_clicked(Graphic& graphic)
{
	sf::Event event;
	graphic.window->pollEvent(event);

	if (event.type == sf::Event::MouseButtonPressed)
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			auto mouse_click_pos = sf::Mouse::getPosition(*graphic.window.get());

			return graphic.check_arena_button_clicked(mouse_click_pos);;
		}
	return ARENA_BUTTON::NONE;
}

void Control::parse_exit_events(sf::Event& event, Graphic& graphic, Game& game)
{
	if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		game.exit();
	else if (event.type == sf::Event::MouseButtonPressed)
		if (event.mouseButton.button == sf::Mouse::Right)
		{
			// TODO: exxit button
		}
}

void Control::parse_walk_events(Graphic& graphic, Game& game)
{
	auto& now = std::chrono::steady_clock::now;

	std::chrono::steady_clock::time_point start = now();
	std::chrono::duration<double> duration;
	// Check all the window's events that were triggered since the last iteration of the loop.
	sf::Event event;
	while (graphic.window->pollEvent(event))
	{
		duration = now() - start;
		if (duration.count() > 0.1)
			break;

		// B || !2B.
		parse_exit_events(event, graphic, game);

		if (parse_move_events(event, graphic, game))
			continue;

		Enemy* enemy = check_mouse_on_enemy_click(event, graphic, game);
		if (enemy != nullptr)
			game.perform_fight(*enemy);

	}
}

bool Control::check_mouse_left_button_clicked(Graphic& graphic)
{
	sf::Event event;
	graphic.window->pollEvent(event);
	return event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left;
}
