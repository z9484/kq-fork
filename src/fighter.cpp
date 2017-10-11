#include "fighter.h"

KFighter::KFighter()
	: fighterName("")
	, fighterExperience(0)
	, fighterMoney(0)
	, fighterLevel(0)
	, fighterImageDatafileX(0)
	, fighterImageDatafileY(0)
	, fighterImageDatafileWidth(0)
	, fighterImageDatafileHeight(0)
	, fighterHealth(0)
	, fighterMaxHealth(0)
	, fighterMagic(0)
	, fighterMaxMagic(0)
	, fighterDefeatItemProbability(0)
	, fighterDefeatItemCommon(0)
	, fighterDefeatItemRare(0)
	, fighterStealItemCommon(0)
	, fighterStealItemRare(0)
	, fighterSpriteFacing(0)
	, fighterAttackSpriteFrame(0)
	, fighterCanCriticalHit(0)
	, fighterWillDefend(0)
	, csmem(0)
	, ctmem(0)
	, current_weapon_type(0)
	, welem(0)
	, unl(0)
	, aux(0)
	, bonus(0)
	, bstat(0)
	, mrp(0)
	, imb_s(0)
	, imb_a(0)
	, img(nullptr)
{
	for (size_t i = 0; i < NUM_STATS; i++)
	{
		fighterStats[i] = 0;
	}
	for (size_t i = 0; i < NUM_RES; i++)
	{
		fighterResistance[i] = 0;
	}
	for (size_t i = 0; i < NUM_SPELL_TYPES; i++)
	{
		fighterSpellEffectStats[i] = 0;
	}
	for (size_t i = 0; i < 8; i++)
	{
		fighterCombatSkill[i] = 0;
	}
	for (size_t i = 0; i < 8; i++)
	{
		aip[i] = 0;
	}
	for (size_t i = 0; i < 8; i++)
	{
		atrack[i] = 0;
	}
	for (size_t i = 0; i < 2; i++)
	{
		imb[i] = 0;
	}
}

/*! Characters when they are in combat */
KFighter fighter[NUM_FIGHTERS];

/*! Temp store for adjusted stats */
KFighter tempa, tempd;
