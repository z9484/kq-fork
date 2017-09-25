#pragma once

#include <allegro.h>

class Raster;

/** Fighter
 *
 * s_player is transformed into a s_fighter during combat.
 * See enemy_init() for more information on the fields.
 */
typedef struct {
	/** Name */
	char fighterName[25];

	/** Experience Points */
	int xp;

	/** Gold Points */
	int gp;

	/** Level */
	int lvl;

	/** x-coord of image in datafile */
	int cx;

	/** y-coord of image in datafile */
	int cy;

	/** width in datafile */
	int cw;

	/** height in datafile */
	int cl;

	/** Hit Points */
	int hp;

	/** Max Hit Points */
	int mhp;

	/** Magic Points */
	int mp;

	/** Max Magic Points */
	int mmp;

	/** Defeat Item Probability: Probability in % that the enemy will yield an item when defeated. */
	int dip;

	/** Defeat Item Common: If the enemy yields an item, you will get this item 95% of the time. */
	int defeat_item_common;

	/** Defeat Item Rare: If the enemy yields an item, you will get this item 5% of the time. */
	int defeat_item_rare;

	/** Steal Item Common: If Ayla steals something, she will get this item 95% of the time. */
	int steal_item_common;

	/** Steal Item Rare: If Ayla steals something, she will get this item 5% of the time. */
	int steal_item_rare;

	/** See A_* constants in kq.h */
	int stats[NUM_STATS];

	/** eResistance: See R_* constants */
	char res[NUM_RES];

	/** Direction character's sprite faces */
	uint8_t facing;

	/** Battle sprite to display (standing, casting, attacking) */
	uint8_t aframe;

	uint8_t crit;

	/** eSpellType */
	uint8_t sts[NUM_SPELLTYPES];

	uint8_t defend;
	uint8_t ai[8];
	uint8_t aip[8];
	uint8_t atrack[8];

	/** Spell number, associated with M_* spells, used within s_spell magic[] array. */
	uint32_t csmem;

	/** Spell target: who is going to be affected by the spell; can be set to -1 */
	int ctmem;

	/** Current Weapon Type: The shape of the currently held weapon (sword, dagger, axe etc) \sa hero_init() */
	uint32_t current_weapon_type;

	/** eResistance: Which Element type (sick, fire, water, etc.) */
	int welem;

	/** UNLiving (undead), like zombies, skeletons, etc. */
	int unl;

	int aux;
	int bonus;
	int bstat;
	int mrp;
	int imb_s;
	int imb_a;
	int imb[2];
	Raster *img;
} s_fighter;
