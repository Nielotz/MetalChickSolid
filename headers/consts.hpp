#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <string>
#include <unordered_map>
#include <vector>

#include "direction.hpp"


namespace PATH
{
    namespace HERO
    {
        namespace TEXTURES
        {
            // XD ):
            typedef std::vector<std::string> strings_vector;
            typedef std::unordered_map<Direction, strings_vector> strings_to_directions_map;
            typedef std::pair<Direction, std::vector<std::string>> strings_to_direction_pair;

			const static strings_to_directions_map warrior = {
				strings_to_direction_pair {
					Direction::LEFT, strings_vector {
					"textures\\mobs\\hero\\left_1_3.tga",
					"textures\\mobs\\hero\\left_2.tga",
					"textures\\mobs\\hero\\left_1_3.tga",
					"textures\\mobs\\hero\\left_4.tga",
					}
				},
			strings_to_direction_pair {
				Direction::RIGHT, strings_vector {
					"textures\\mobs\\hero\\right_1_3.tga",
					"textures\\mobs\\hero\\right_2.tga",
					"textures\\mobs\\hero\\right_1_3.tga",
					"textures\\mobs\\hero\\right_4.tga",
					},
				},
			strings_to_direction_pair {
				Direction::BOTTOM, strings_vector{
					"textures\\mobs\\hero\\front_1_3.tga",
					"textures\\mobs\\hero\\front_2.tga",
					"textures\\mobs\\hero\\front_1_3.tga",
					"textures\\mobs\\hero\\front_4.tga",
					},
				},
			strings_to_direction_pair {
				Direction::TOP, strings_vector{
					"textures\\mobs\\hero\\back_1_3.tga",
					"textures\\mobs\\hero\\back_2.tga",
					"textures\\mobs\\hero\\back_1_3.tga",
					"textures\\mobs\\hero\\back_4.tga",
					}
				}
			};
		}
	};

	namespace ENTITY_TEXTURES
	{
		namespace BEAR
		{
			const static std::string MAP = "textures\\mobs\\mobsmobs\\bear_map.tga";
			const static std::string ARENA = "textures\\mobs\\mobsmobs\\bear_map.tga";

		}
	}

	namespace MAP
	{
		namespace TEXTURES
		{
			const static std::string TEST = "textures\\maps\\test_map.tga";
			const static std::string START = "textures\\maps\\start_map.tga";
			const static std::string FOREST = "textures\\maps\\forest_map.tga";

		}
	}

	namespace UI
	{
		namespace TEXTURES
		{
			const static std::string WALK_UI_RIGHT_PANEL = "textures\\ui\\UI_map.tga";

		}
	}

	namespace TUTORIAL
	{
		namespace TEXTURES
		{
			const static std::string TUT = "textures\\maps\\tut.tga";
		}
	}
};

struct CONSTS
{
	const static sf::Vector2u BASE_SCREEN_SIZE;
	const static sf::Vector2u GAME_SCREEN_RATIO;
	const static sf::Vector2u SCREEN_SIZE;
	const static sf::Vector2u GAME_WINDOW_SIZE;

    // Scales everything to appear same on every screen.
    const static long double SCALE;

    const static uint16_t TILE_SIZE_ON_TEXTURE_MAP; // Pixels.
    // Tile size in game.
    const static uint16_t TILE_SIZE; // Pixels.

    // In tiles. 
    const static sf::Vector2u PLAYER_VIEW_RANGE;

    // Applies only when view can move (when hero is far from the borders).
    const static uint8_t MIN_PLAYER_DISTANCE_TO_BORDER;
};



