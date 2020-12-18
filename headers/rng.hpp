#pragma once

class rng
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> small_distribution = std::uniform_int_distribution<int> (90, 110);
    std::uniform_int_distribution<int> percentage_distribution = std::uniform_int_distribution<int>(0, 100);

};

