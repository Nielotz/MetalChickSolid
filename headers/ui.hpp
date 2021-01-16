#include <unordered_map>

enum class UI_TYPE
{
	WALK = 0,
	FIGHT = 1
};

class UIBase
{
protected:
	std::pair<sf::Sprite, sf::Texture> ui_sprite_with_texture;

public:
	UI_TYPE ui_type;
	void load_right_panel_texture(const std::string& path);

	// Position on left top corner in pixels.
	void set_position(float x, float y);

	void draw(sf::RenderWindow& window);
};

class ArenaUI : public UIBase
{};

class WalkUI : public UIBase
{};

class UI
{
public:
	UI() = default;

	WalkUI walk_UI;
	ArenaUI arena_UI;

	// Load PANEL textures.
	void load_panels_textures(const std::string& walk, const std::string& arena);

	void draw(sf::RenderWindow& window, UI_TYPE& UI_type);
};