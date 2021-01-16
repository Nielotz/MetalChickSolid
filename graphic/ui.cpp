#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../headers/ui.hpp"
#include "../headers/consts.hpp"

void UI::load_panels_textures(const std::string& walk, const std::string& arena)
{
	walk_UI.load_right_panel_texture(walk);
	arena_UI.load_right_panel_texture(arena);
}

void UI::draw(sf::RenderWindow& window, UI_TYPE& UI_type)
{
	if (UI_type == UI_TYPE::WALK)
		walk_UI.draw(window);
	else
		arena_UI.draw(window);
}

void UIBase::load_right_panel_texture(const std::string& path)
{
	sf::Sprite& sprite = ui_sprite_with_texture.first;
	sf::Texture& texture = ui_sprite_with_texture.second;

	if (!texture.loadFromFile(path))
		throw std::runtime_error("Cannot load " + path);

	texture.setSmooth(true);

	sprite.setTexture(texture);

	float scale = float(double(CONSTS::TILE_SIZE * 6. ) / double(texture.getSize().x));

	sprite.setScale(sf::Vector2f{ scale, scale });
}

void UIBase::set_position(float x, float y)
{
	sf::Sprite& sprite = ui_sprite_with_texture.first;

	sprite.setPosition(x, y);
}

void UIBase::draw(sf::RenderWindow& window)
{
	window.draw(ui_sprite_with_texture.first);
}
