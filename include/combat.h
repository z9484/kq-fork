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

#define BATTLE_INC 20
#define ROUND_MAX 400
#define DMG_RND_MIN 2

class Raster;

/*! \name combat function prototypes  */
int combat_check(int, int);
int combat(int);
void battle_render(signed int, size_t, int);
void draw_fighter(size_t, size_t);
int fight(size_t, size_t, int);
void multi_fight(size_t);
void fkill(size_t);

/*!  global combat related variables  */
enum ECombatEnd
{
	STILL_IN_COMBAT = 0,
	EVERYONE_DEFEATED = 1,
	ESCAPED_COMBAT = 2,
};
extern ECombatEnd combatend;
extern bool bIsEtherEffectActive[NUM_FIGHTERS];
extern int curx;
extern int cury;
extern uint32_t num_enemies;
extern int ta[NUM_FIGHTERS];
extern int deffect[NUM_FIGHTERS];
extern int rcount;
extern uint8_t vspell;
extern uint8_t ms;
extern Raster* backart;
