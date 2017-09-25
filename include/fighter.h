#pragma once

#include <allegro.h>

class Raster;

/** Fighter
 *
 * s_player is transformed into a s_fighter during combat.
 * See enemy_init() for more information on the fields.
 */
typedef struct {
	char name[25];          /** Name */
	int xp;                 /** Experience Points */
	int gp;                 /** Gold Points */
	int lvl;                /** Level */
	int cx;                 /** x-coord of image in datafile */
	int cy;                 /** y-coord of image in datafile */
	int cw;                 /** width in datafile */
	int cl;                 /** height in datafile */
	int hp;                 /** Hit Points */
	int mhp;                /** Max Hit Points */
	int mp;                 /** Magic Points */
	int mmp;                /** Max Magic Points */
	int dip;                /** Defeat Item Probability: Probability in % that the enemy will yield an item when defeated. */
	int defeat_item_common; /** Defeat Item Common: If the enemy yields an item, you will get this item 95% of the time. */
	int defeat_item_rare;   /** Defeat Item Rare: If the enemy yields an item, you will get this item 5% of the time. */
	int steal_item_common;  /** Steal Item Common: If Ayla steals something, she will get this item 95% of the time. */
	int steal_item_rare;    /** Steal Item Rare: If Ayla steals something, she will get this item 5% of the time. */
	int stats[NUM_STATS];   /** See A_* constants in kq.h */
	char res[NUM_RES];      /** eResistance: See R_* constants */
	uint8_t facing;         /** Direction character's sprite faces */
	uint8_t aframe;         /** Battle sprite to display (standing, casting, attacking) */
	uint8_t crit;
	uint8_t sts[NUM_SPELLTYPES]; /** eSpellType */
	uint8_t defend;
	uint8_t ai[8];
	uint8_t aip[8];
	uint8_t atrack[8];
	uint32_t csmem;         /** Spell number, associated with M_* spells, used within s_spell magic[] array. */
	int ctmem;              /** Spell target: who is going to be affected by the spell; can be set to -1 */
	uint32_t current_weapon_type; /** Current Weapon Type: The shape of the currently held weapon (sword, dagger, axe etc) \sa hero_init() */
	int welem;              /** eResistance: Which Element type (sick, fire, water, etc.) */
	int unl;                /** UNLiving (undead), like zombies, skeletons, etc. */
	int aux;
	int bonus;
	int bstat;
	int mrp;
	int imb_s;
	int imb_a;
	int imb[2];
	Raster *img;
} s_fighter;
