#pragma once

#include <stdlib.h>
/*! \file
 * \brief Hero combat header file
 */

/*! \name Hero identifiers */
enum ePIDX {
  PIDX_UNDEFINED = -1,
  SENSAR = 0,
  SARINA = 1,
  CORIN = 2,
  AJATHAR = 3,
  CASANDRA = 4,
  TEMMIN = 5,
  AYLA = 6,
  NOSLOM = 7,

  MAXCHRS,

  SEL_ALL_ALLIES,
  SEL_ALL_ENEMIES
};

extern int can_use_item; /* intrface.c */

void hero_init(void);            /*  combat.c  */
void hero_choose_action(size_t); /*  combat.c  */
void auto_herochooseact(int);    /*  combat.c  */
int available_spells(int);       /*  hskill.c  */
int combat_spell_menu(int);      /*  hskill.c  */
