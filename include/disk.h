#pragma once

#include "maps.h"
#include "player.h"
#include "structs.h"

int load_s_player(KPlayer*, PACKFILE*);
int save_s_player(KPlayer*, PACKFILE*);
int load_game_xml(const char*);
int save_game_xml(const char*);
int load_stats_only(const char*, s_sgstats&);
