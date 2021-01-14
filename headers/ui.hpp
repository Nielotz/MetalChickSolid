#include <unordered_map>

enum class UI_TYPE
{
	WALK = 0,
	FIGHT = 1
};

class WalkUI
{
	std::unordered_map<UI_TYPE, std::pair<sf::Sprite, sf::Texture>> ui_sprite_with_texture;

public:
	WalkUI();

	void load_right_panel_texture(const std::string& path);

	// Position on left top corner in pixels.
	void set_position(float x, float y);

	void draw(sf::RenderWindow& window);
};

class UI
{
public:
	UI() = default;

	WalkUI walk_UI;

	// Load UI textures.
	void load_textures(const std::string& path);

	void draw(sf::RenderWindow& window, UI_TYPE& UI_type);
};