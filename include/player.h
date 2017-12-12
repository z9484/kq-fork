#pragma once

#include <string>

#include "enums.h"
#include "res.h"

/** \brief Player */
class KPlayer
{
public:
    KPlayer();
    ~KPlayer();

public:
    // Entity name (was: char playerName[9])
    std::string playerName;

    // Entity experience
    int xp;

    // Experience needed for level-up
    int next;

    // Entity's level
    int lvl;

    // Magic use rate (0-100)
    int mrp;

    // Hit points
    int hp;

    // Maximum hit points
    int mhp;

    // Magic points
    int mp;

    // Maximum magic points
    int mmp;

    int stats[NUM_STATS];
    // eResistance: See R_* constants
    char res[NUM_RES];

    // eSpellType
    uint8_t sts[NUM_SPELL_TYPES];

    // eEquipment: Weapons, armor, etc. equipped
    uint8_t eqp[NUM_EQUIPMENT];

    // Known spells
    uint8_t spells[NUM_SPELLS];

    /** Level-up information
    * Item 0, 1 - used to calculate the XP you need for the next level
    * Item 2 - Boost to your HP/MHP
    * Item 3 - Boost to your MP/MMP
    * Items 4..16 - Actually used by player2fighter to adjust your base stats to the level you're on.
    */
    unsigned short lup[NUM_LUP];
};
 