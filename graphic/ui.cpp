#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../headers/ui.hpp"
#include "../headers/consts.hpp"


void UI::load_textures(const std::string& right_panel)
{
	walk_UI.load_right_panel_texture(right_panel);
}

void UI::draw(sf::RenderWindow& window, UI_TYPE& UI_type)
{
	if (UI_type == UI_TYPE::WALK)
		walk_UI.draw(window);
}

WalkUI::WalkUI()
{
	typedef std::pair<UI_TYPE, std::pair<sf::Sprite, sf::Texture>> sth_i_dont_care;

	ui_sprite_with_texture.insert(sth_i_dont_care(UI_TYPE::WALK, {}));
}

void WalkUI::load_right_panel_texture(const std::string& path)
{
	sf::Sprite& sprite = ui_sprite_with_texture.at(UI_TYPE::WALK).first;
	sf::Texture& texture = ui_sprite_with_texture.at(UI_TYPE::WALK).second;

	if (!texture.loadFromFile(path))
		throw std::runtime_error("Cannot load " + path);

	texture.setSmooth(true);

	sprite.setTexture(texture);

	float scale = float(CONSTS::TILE_SIZE * 3 ) / float(texture.getSize().x);

	sprite.setScale(sf::Vector2f{ scale, scale });
}

void WalkUI::set_position(float x, float y)
{
	sf::Sprite& sprite = ui_sprite_with_texture.at(UI_TYPE::WALK).first;

	sprite.setPosition(x, y);
}


void WalkUI::draw(sf::RenderWindow& window)
{
	sf::Sprite& sprite = ui_sprite_with_texture.at(UI_TYPE::WALK).first;

	window.draw(sprite);
}

