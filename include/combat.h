#pragma once

/*! \file
 * \brief Combat header file
 *
 * This file contains prototype for functions
 * related to drawing characters in combat and
 * to calculating the outcomes of combat
 * \author JB
 * \date ????????
 */

#include "enums.h"
#include <stdint.h>
#include <string>

constexpr uint16_t BATTLE_INC = 20;
constexpr uint16_t ROUND_MAX = 400;
constexpr uint16_t DMG_RND_MIN = 2;

enum ECombatEnd
{
    NOT_IN_COMBAT,
    STILL_IN_COMBAT,
    EVERYONE_DEFEATED,
    ESCAPED_COMBAT,
};

class Raster;

class KCombat
{
public:
    KCombat();
    ~KCombat();

    /**
     * Main combat function
     *
     * The big one... I say that because the game is mostly combat :p
     * First, check to see if a random encounter has occurred. The check is skipped
     * if it's a scripted battle.  Then call all the helper and setup functions
     * and start the combat by calling do_round.
     *
     * \param   battleIdentifier Combat identifier (index into battles[])
     * \returns 0 if no combat, 1 otherwise
     */
    int combat(size_t battleIdentifier);

    /**
     * Draw the battle screen
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated 20020914 - 16:16 (RB)
     *
     * Draw the battle screen.
     *
     * \param   plyr Player: -1 means "no one is selected" (roll_initiative()), else
     * index of fighter
     * \param   hl Highlighted
     * \param   sall Select all
     */
    void battle_render(signed int plyr, size_t hl, int sall);

    /**
     * Display one fighter on the screen
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated 20020914 - 16:37 (RB)
     * \date Updated 20031009 PH (put fr-> instead of fighter[fighter_index]. every
     * time)
     *
     * Display a single fighter on the screen. Checks for dead and
     * stone, and if the fighter is selected. Also displays 'Vision'
     * spell information.
     */
    void draw_fighter(size_t fighter_index, size_t dcur);

    /**
     * Main fighting routine
     *
     * I don't really need to describe this :p
     *
     * \author Josh Bolduc
     * \date created ????????
     * \date updated

     * \param   attack_fighter_index Attacker ID
     * \param   defend_fighter_index Defender ID
     * \param   sk If non-zero, override the attacker's stats.
     * \returns 1 if damage done, 0 otherwise
     */
    int fight(size_t attack_fighter_index, size_t defend_fighter_index, int sk);

    /**
     * Attack all enemies at once
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated
     *
     * This is different than fight in that all enemies are attacked
     * simultaneously, once. As a note, the attackers stats are
     * always over-ridden in this function. As well, critical hits
     * are possible, but the screen doesn't flash.
     *
     * \param   attack_fighter_index Attacker
     */
    void multi_fight(size_t attack_fighter_index);

    /**
     * Kill a fighter
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated 20020917 (PH) -- added cheat mode
     *
     * Do what it takes to put a fighter out of commission.
     *
     * \param   fighter_index The one who will die
     */
    void fkill(size_t fighter_index);

public:
    ECombatEnd combatend;
    bool bIsEtherEffectActive[NUM_FIGHTERS];
    int fighterImageDatafileX;
    int fighterImageDatafileY;
    uint32_t num_enemies;
    int ta[NUM_FIGHTERS];
    int deffect[NUM_FIGHTERS];
    uint16_t rcount;
    uint8_t vspell;
    uint8_t ms;
    Raster* backart;

private:
    enum eAttackResult
    {
        ATTACK_MISS,
        ATTACK_SUCCESS,
        ATTACK_CRITICAL
    };

    /**
     * Attack all enemies at once
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated
     *
     * This does the actual attack calculation. The damage done to
     * the target is kept in the ta[] array.
     *
     * \param   ar Attacker
     * \param   dr Defender
     * \returns ATTACK_MISS if attack was a miss,
     *          ATTACK_SUCCESS if attack was successful,
     *          ATTACK_CRITICAL if attack was a critical hit.
     */
    eAttackResult attack_result(int ar, int dr);

    /**
     * Check whether all heroes or enemies are dead.
     *
     * A battle is over when either all heroes or all enemies are defeated.
     *
     * @return true if the battle ended (either heroes/enemies won), false otherwise.
     */
    bool hasBattleEnded();

    /**
     * Choose an action
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated
     *
     * Choose a fighter action.
     */
    void do_action(size_t fighter_index);

    /**
     * Really do combat once fighters have been inited
     *
     * \param   bno Combat identifier (index into battles[])
     * \returns 1 if battle occurred
     */
    int KCombat::do_combat(size_t bno);

    /**
     * Really do combat once fighters have been inited
     *
     * \param   backgroundImageName Background image
     * \param   mus Music
     * \param   is_rnd If !=0 then this is a random combat
     * \returns 1 if battle occurred
     */
    int do_combat(const std::string& backgroundImageName, char* mus, int is_rnd);

    /**
     * Battle gauge, action controls
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated 20020914 - 16:16 (RB)
     *
     * This function controls the battle gauges and calls for action
     * when necessary. This is also where things like poison, sleep,
     * and what-not are checked.
     */
    void do_round();

    /**
     * Enemies defeated the player
     * \author Josh Bolduc
     * \date created ????????
     * \date updated
     *
     * Play some sad music and set the dead flag so that the game
     * will return to the main menu.
     */
    void enemies_win() const;

    /**
     * Player defeated the enemies
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated
     *
     * Distribute the booty!
     */
    void heroes_win();

    /**
     * Initiate fighter structs and initial vars
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated
     *
     * Pre-combat setup of fighter structures and initial vars.
     */
    void init_fighters();

    /**
     * Choose who attacks first, speeds, etc.
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated
     *
     * Set up surprise vars, speeds, act vars, etc.
     */
    void roll_initiative();

    /**
     * Fighter on-screen locations in battle
     * \author Josh Bolduc
     * \date Created ????????
     * \date Updated
     *
     * Calculate where the fighters should be drawn.
     */
    void snap_togrid();

private:
    int curw;
    int nspeed[NUM_FIGHTERS];
    int bspeed[NUM_FIGHTERS];
    uint8_t hs;
};

// Global
extern KCombat kqCombat;
