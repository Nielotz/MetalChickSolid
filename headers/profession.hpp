#pragma once


enum class ProfessionType : uint8_t
{
    NONE = 0, // Not defined.
    //HERO
    WARRIOR = 1,
    HUNTER = 2,
    MAGICIAN = 3,
    //NPC
    NPC_TALKATIVE=10,
    NPC_BEATABLE=11,
    //ITEMS AND OTHERS
    ITEM=12,
    ANY = 100
};
