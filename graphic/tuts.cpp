#include "..\headers\tuts.hpp"
#include "..\headers\consts.hpp"

void TutorialGraphic::load_tutorial_texture(const std::string& path)
{

	if (!texture.loadFromFile(path))
		throw std::runtime_error("Cannot load " + path);

	texture.setSmooth(true);

	sprite.setTexture(texture);

	float scale = std::min<float>(
		(float)((double)CONSTS::GAME_WINDOW_SIZE.x / texture.getSize().x),
		(float)((double)CONSTS::GAME_WINDOW_SIZE.y / texture.getSize().y));

	sprite.setScale(sf::Vector2f{ scale, scale });
	sprite.setPosition(0, 0);
}

void TutorialGraphic::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
