#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class TutorialGraphic
{
	sf::Sprite sprite;
	sf::Texture texture;

public:
	TutorialGraphic()=default;
	void load_tutorial_texture(const std::string& path);
	void draw(sf::RenderWindow& window);
};
