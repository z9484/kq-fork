#pragma once

#include "entity.h"
#include "maps.h"
#include "structs.h"

int save_s_entity(KQEntity*, PACKFILE*);
int load_s_player(s_player*, PACKFILE*);
int save_s_player(s_player*, PACKFILE*);
int load_game_xml(const char*);
int save_game_xml(const char*);
int load_stats_only(const char*, s_sgstats&);
