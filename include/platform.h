#pragma once

/*! \file
 * \brief Platform-specific interfaces, prototypes, and #defines
 * \author OC
 * \date 20100221
 */

#include <string>
using std::string;

enum eDirectories {
  DATA_DIR = 0,
  MAP_DIR = 1,
  SAVE_DIR = 2,
  MUSIC_DIR = 3,
  SCRIPT_DIR = 4,
  SETTINGS_DIR = 5,
};

/* Get the directory for application data (music, gfx, etc.)
   or user data (screenshots, prefs, saved games)
 */
const string kqres(enum eDirectories, const string);

const string get_lua_file_path(const string, const string);
const string get_resource_file_path(const string, const string, const string);

#define maybe_poll_joystick poll_joystick
