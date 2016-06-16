/*! \page License
   KQ is Copyright (C) 2002 by Josh Bolduc

   This file is part of KQ... a freeware RPG.

   KQ is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 2, or (at your
   option) any later version.

   KQ is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with KQ; see the file COPYING.  If not, write to
   the Free Software Foundation,
       675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __KQ_H
#define __KQ_H 1

/*! \file
 * \brief Main include file for KQ
 * \author JB
 * \date ??????
 */

/* Have to undef some stuff because Allegro defines it - thanks guys
*/
#ifdef HAVE_CONFIG_H
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_BUGREPORT
#include "config.h"
#endif

#ifdef __GNUC__
#define NORETURN __attribute__((noreturn))
#else
#ifdef _MSC_VER
#define NORETURN __declspec(noreturn)
#else
#define NORETURN
#endif /* MSVC */
#endif /* GNUC */

#include <stdint.h>
#include <string>

#include "gettext.h"
#define _(s) gettext(s)

#include "entity.h"
#include "enums.h"
#include "heroc.h"
#include "maps.h"
#include "structs.h"

class Raster;

class KGame {
public:
  void change_map(const std::string &, int, int, int,
                  int); /*  intrface.c, magic.c  */
  void change_mapm(const std::string &, const std::string &, int,
                   int);         /*  intrface.c */
  void readcontrols(void);       /*  everywhere ;)  */
  void calc_viewport(int);       /*  entity.c, intrface.c  */
  void zone_check(void);         /*  entity.c  */
  void warp(int, int, int);      /*  only in intrface.c  */
  void do_check_animation(void); /*  draw.c, intrface.c  */
  void activate(void);           /*  only in entity.c  */
  void unpress(void);            /*  everywhere ;)  */
  void wait_enter(void);         /*  everywhere ;)  */
  void klog(const char *);       /*  draw.c, intrface.c, magic.c, setup.c  */
  void init_players(void);       /*  sgame.c  */
  void kwait(int);               /*  intrface.c  */
  NORETURN void program_death(const char *); /*  everywhere ;)  */
  size_t in_party(ePIDX);                    /*  combat.c, intrface.c  */
  void wait_for_entity(size_t, size_t);      /*  intrface.c  */
  char *get_timer_event(void);               /*  entity.c, kq.c  */
  int add_timer_event(const char *, int);    /*  intrface.c  */
  void reset_timer_events(void);             /*  intrface.c  */
  void reset_world(void);                    /*  sgame.c  */

  /*! Yield processor to other tasks */
  void kq_yield(void);

  Raster *alloc_bmp(int bitmap_width, int bitmap_height,
                    const char *bitmap_name);

  void startup(void);
  void deallocate_stuff(void);

  void allocate_stuff(void);
  void load_heroes(void);
  void prepare_map(int, int, int, int);
  void data_dump(void);
};

extern std::string curmap; /*  sgame.c, draw.c, magic.c */
extern s_player_input PlayerInput;
extern int vx, vy, mx, my, steps, lastm[PSIZE];

extern Raster *double_buffer, *fx_buffer;
extern Raster *map_icons[MAX_TILES];

extern Raster *back, *tc, *tc2, *bub[8], *b_shield, *b_shell, *b_repulse, *b_mp;
extern Raster *cframes[NUM_FIGHTERS][MAXCFRAMES],
    *tcframes[NUM_FIGHTERS][MAXCFRAMES], *frames[MAXCHRS][MAXFRAMES];
extern Raster *eframes[MAXE][MAXEFRAMES], *pgb[9], *sfonts[5], *bord[8];
extern Raster *menuptr, *mptr, *sptr, *stspics, *sicons, *bptr, *missbmp,
    *noway, *upptr, *dnptr;
extern Raster *shadow[MAX_SHADOWS]; /*  draw.c  */
extern unsigned short *map_seg;
extern unsigned short *b_seg, *f_seg;
extern unsigned char *z_seg, *s_seg, *o_seg;
extern unsigned char progress[SIZE_PROGRESS];
extern unsigned char treasure[SIZE_TREASURE];
extern unsigned char save_spells[SIZE_SAVE_SPELL];
extern Raster *kfonts;
extern s_map g_map;
extern s_entity g_ent[MAX_ENTITIES];
extern s_anim tanim[MAX_TILESETS][MAX_ANIM];
extern s_anim adata[MAX_ANIM];
extern uint32_t numchrs;
extern int gp, xofs, yofs, gsvol, gmvol;
extern uint32_t noe;
extern ePIDX pidx[MAXCHRS];
extern uint8_t autoparty, alldead, is_sound, deadeffect, vfollow, use_sstone,
    sound_avail;
extern const uint8_t kq_version;
extern uint8_t hold_fade, cansave, skip_intro, wait_retrace, windowed,
    stretch_view, cpu_usage;
extern uint16_t tilex[MAX_TILES], adelay[MAX_ANIM];
extern char *strbuf, *savedir;
extern s_player party[MAXCHRS];
extern s_heroinfo players[MAXCHRS];
extern s_fighter fighter[NUM_FIGHTERS];
extern s_fighter tempa, tempd;
extern int shin[12], display_attack_string;
extern string shop_name;
extern char attack_string[39];
extern volatile int timer, ksec, kmin, khr, animation_count, timer_count;
extern COLOR_MAP cmap;
extern uint8_t can_run, display_desc;
extern uint8_t draw_background, draw_middle, draw_foreground, draw_shadow;
extern s_inventory g_inv[MAX_INV];
extern s_special_item special_items[MAX_SPECIAL_ITEMS];
extern short player_special_items[MAX_SPECIAL_ITEMS];
extern int view_x1, view_y1, view_x2, view_y2, view_on, in_combat;
extern int show_frate, use_joy;

/*! Variables used with KQ_CHEATS */
extern int cheat;
extern int no_random_encounters;
extern int every_hit_999;
extern int no_monsters;

#ifdef DEBUGMODE
extern Raster *obj_mesh;
#endif

/* The same blit() function was called all over the place, so this simplifies
 * the call.
 * 352 == (320 + 16 + 16) or screen dimensions plus 1 tile on left and 1 tile
 * on right.
 * 272 == (240 + 16 + 16) or screen dimensions plus 1 tile on top and 1 tile
 * on bottom.
 */
#define SCREEN_W2 (320 + 2 * TILE_W)
#define SCREEN_H2 (240 + 2 * TILE_H)
#define fullblit(a, b) blit((a), (b), 0, 0, 0, 0, SCREEN_W2, SCREEN_H2)

extern KGame Game;

#ifndef TRACE
extern void TRACE(const char *message, ...);
#endif
#endif /* __KQ_H */
