#pragma once

#include <string>

#include "hero.hpp"

struct Profile
{
    Hero hero;

    /// Path to the profile.
    std::string path;

    /// Name of the profile.
    std::string name;

    /// Create new profile.
    void create_new();

    /// Load profile from the file.
    /// Requires path to be set.
    void load();

    /// Save profile into the file.
    /// Requires path to be set.
    void save();

    Profile() = default;
};
