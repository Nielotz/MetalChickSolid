#pragma once
#include "graphic.hpp"

// Handles input events.
class Control
{
public:
    // React to game control events.
    //
    // Supported events:
    // Close
    void parse_move_events(Graphic& graphic);
    Control() = default;

};