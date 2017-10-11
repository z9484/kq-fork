#pragma once

#include "kq.h"

class KSaveGame
{
public:
	void load_sgstats(void);
	int start_menu(int);
	int system_menu(void);

protected:
	void show_sgstats(int);
	int save_game(void);
	int load_game(void);
	void delete_game(void);
	int saveload(int);
	int confirm_action(void);

protected:
	/* Number of save game slots */
	const static int NUMSG = 20;

	/* These describe the save slots. Number of characters, gp, etc */
	/* They are used to make the save menu prettier. */
	s_sgstats savegame[NUMSG];

	/* Which save_slot the player is pointing to */
	int save_ptr = 0;

	/* Which save_slot is shown at the top of the screen (for scrolling) */
	int top_pointer = 0;

	/* Maximum number of slots to show on screen. */
	int max_onscreen = 5;
};

extern KSaveGame SaveGame;
