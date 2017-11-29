#pragma once

/*! \file
 * \brief Stuff related to entities on the map
 *
 * An entity is a hero, or an NPC.
 * \author JB
 * \date ??????
 */

typedef uint32_t t_entity;

void process_entities(void);

/*! \brief Check entities at location
*
* Check for any entities in the specified coordinates. Runs combat routines if a
* character and an enemy meet, and deactivate the enemy if it was defeated.
*
* @param ox x-coordinate to check
* @param oy y-coordinate to check
* @param who Id of entity doing the checking
* @return index+1 of entity found or 0 if none found.
*/
int entityat(int ox, int oy, t_entity who);

void set_script(t_entity, const char*);
void place_ent(t_entity, int, int);
void count_entities(void);

enum eCommands
{
	COMMAND_NONE = 0,
	COMMAND_MOVE_UP = 1,
	COMMAND_MOVE_DOWN = 2,
	COMMAND_MOVE_LEFT = 3,
	COMMAND_MOVE_RIGHT = 4,
	COMMAND_WAIT = 5,
	COMMAND_FINISH_COMMANDS = 6,
	COMMAND_REPEAT = 7,
	COMMAND_MOVETO_X = 8,
	COMMAND_MOVETO_Y = 9,
	COMMAND_FACE = 10,
	COMMAND_KILL = 11,

	NUM_COMMANDS // always last
};
