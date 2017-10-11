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
int entityat(int, int, t_entity);
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
