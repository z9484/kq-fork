#pragma once

#include "enums.h"
#include "heroc.h"

int select_player(void);
ePIDX select_any_player(eTarget, unsigned int, const char *);
ePIDX select_hero(size_t, eTarget, bool);
ePIDX select_enemy(size_t, eTarget);
int auto_select_hero(int, int);
int auto_select_enemy(int, int);
int select_party(ePIDX *, size_t, size_t);
void party_newlead(void);
