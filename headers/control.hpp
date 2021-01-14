#pragma once
#include "graphic.hpp"

class Game;


// Handles input events.
class Control
{
    // Parse WASD events.
    // Return whether parsed event.
    bool parse_move_events(sf::Event& event, Graphic& graphic, Game& game);

    // May close application!
    void parse_exit_events(sf::Event& event, Graphic& graphic, Game& game);

public:
    // React to game control events.
    //
    // Supported events:
    // Close
    void parse_walk_events(Graphic& graphic, Game& game);

    Control() = default;

};