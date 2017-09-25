#pragma once

#include <string>

#include <allegro.h>

class Raster;

/** Fighter
 *
 * s_player is transformed into a s_fighter during combat.
 * See enemy_init() for more information on the fields.
 */
typedef struct {
	/** Name */
	std::string fighterName;

	/** Experience Points */
	int fighterExperience;

	/** Gold Points */
	int fighterMoney;

	/** Level */
	int fighterLevel;

	/** x-coord of image in datafile */
	int fighterImageDatafileX;

	/** y-coord of image in datafile */
	int fighterImageDatafileY;

	/** width in datafile */
	int fighterImageDatafileWidth;

	/** height in datafile */
	int fighterImageDatafileHeight;

	/** Hit Points */
	int fighterHealth;

	/** Max Hit Points */
	int fighterMaxHealth;

	/** Magic Points */
	int fighterMagic;

	/** Max Magic Points */
	int fighterMaxMagic;

	/** Defeat Item Probability: Probability in % that the enemy will yield an item when defeated. */
	int fighterDefeatItemProbability;

	/** Defeat Item Common: If the enemy yields an item, you will get this item 95% of the time. */
	int fighterDefeatItemCommon;

	/** Defeat Item Rare: If the enemy yields an item, you will get this item 5% of the time. */
	int fighterDefeatItemRare;

	/** Steal Item Common: If Ayla steals something, she will get this item 95% of the time. */
	int fighterStealItemCommon;

	/** Steal Item Rare: If Ayla steals something, she will get this item 5% of the time. */
	int fighterStealItemRare;

	/** See A_* constants in kq.h */
	int fighterStats[NUM_STATS];

	/** eResistance: See R_* constants */
	char fighterResistance[NUM_RES];

	/** Direction character's sprite faces */
	uint8_t fighterSpriteFacing;

	/** Battle sprite to display (standing, casting, attacking) */
	uint8_t fighterAttackSpriteFrame;

	/** Player frequently (or always) gets a "critical hit" buff (Sensar's "rage") */
	uint8_t fighterCanCriticalHit;

	/** eSpellType */
	uint8_t sts[NUM_SPELLTYPES];

	/** Fighter will defend (instead of attack or use an item) for this turn during battle. */
	uint8_t fighterWillDefend;
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
