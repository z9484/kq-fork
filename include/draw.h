#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string>

class Raster;

// TODO: Find out whether these values paired to any color defined within
// PALETTE 'pal'
constexpr uint8_t GREY1 = 4;
constexpr uint8_t GREY2 = 8;
constexpr uint8_t GREY3 = 13;
constexpr uint8_t WHITE = 15;
constexpr uint8_t DBLUE = 3;
constexpr uint8_t DRED = 6;

enum eFontColor
{
	FNORMAL = 0,
	FRED = 1,
	FYELLOW = 2,
	FGREEN = 3,
	FDARK = 4,
	FGOLD = 5,
	FBIG = 6,

	NUM_FONT_COLORS // always last
};

enum eFont
{
	FONT_WHITE = 0,
	FONT_RED,
	FONT_YELLOW,
	FONT_GREEN,
	FONT_PURPLE,
	FONT_DECIDE,

	NUM_FONTS // always last
};

enum eBubbleStyle
{
	B_TEXT = 0,
	B_THOUGHT = 1,
	B_MESSAGE = 2,

	NUM_BUBBLE_STYLES // always last
};

/* These should correspond with the stems found in MISC.
 * Bubbles are either solid (for speech) or wavy (for thoughts).
 */
enum eBubbleStemStyle
{
	STEM_UNDEFINED = -1,

	STEM_BOTTOM_RIGHT = 0,
	STEM_BOTTOM_LEFT = 1,
	STEM_TOP_RIGHT = 2,
	STEM_TOP_LEFT = 3,

	NUM_BUBBLE_STEMS // always last
};

/*  draw global functions  */

void blit2screen(int, int);
void color_scale(Raster*, Raster*, int, int);
void convert_cframes(size_t, int, int, int);
void revert_cframes(size_t, int);
void draw_icon(Raster*, int, int, int);
void draw_stsicon(Raster*, int, int, int, int, int);
int is_forestsquare(int, int);
void drawmap(void);
void menubox(Raster* where, int x, int y, int w, int h, int c);
void print_font(Raster* where, int sx, int sy, const char* msg, eFontColor font_index);
void print_num(Raster* where, int sx, int sy, const std::string& msg, eFont font_index);
void text_ex(int, int, const char*);

/*! \brief Display speech/thought bubble with portrait
 * \author Z9484
 * \date 2008
 *
 * Displays text, like bubble_text, but passing the args
 * through the relay function first
 * \date updated 20030401 merged thought and speech
 * \sa bubble_text()
 * \param   fmt Format, B_TEXT or B_THOUGHT
 * \param   who Character that is speaking
 * \param   s The text to display
 */
void porttext_ex(eBubbleStyle fmt, int who, const char* s);
int prompt(int, int, int, const char*, const char*, const char*, const char*);
int prompt_ex(int, const char*, const char* [], int);
void message(const char*, int, int, int, int);
void set_view(int, int, int, int, int);

Raster* copy_bitmap(Raster* target, Raster* source);

/*  global variables  */
extern uint8_t BLUE;
extern uint8_t DARKBLUE;
extern uint8_t DARKRED;
