/*! \file
 * \brief Specifics for Windows
 *
 * \author PH
 * \date 20030723
 *
 * This includes any bits which are specific for Windows platforms
 */

#include "kq.h"
#include "platform.h"
#include <allegro.h>

#include <cstdarg>
#include <string>

// This clashes with a Windows typedef
#undef PSIZE
#include <winalleg.h>

static int init_path = 0;
static char user_dir[MAX_PATH];
static char game_dir[MAX_PATH];
typedef HRESULT(WINAPI* SHGETFOLDERPATH)(HWND, int, HANDLE, DWORD, LPWSTR);

#define CSIDL_FLAG_CREATE 0x8000
#define CSIDL_APPDATA 0x1A
#define SHGFP_TYPE_CURRENT 0

namespace
{
const string CombinePaths(size_t numStringsToCombine, ...)
{
	string constructedPath = "";

	if (numStringsToCombine == 0)
	{
		return constructedPath;
	}

	va_list args;
	va_start(args, numStringsToCombine);
	constructedPath += va_arg(args, std::string);
	for (size_t i = 1; i < numStringsToCombine; i++)
	{
		constructedPath += "/";
		constructedPath += va_arg(args, std::string);
	}

	return constructedPath;
}

} // anonymous namespace

/*! \brief Returns the full path for this file
 *
 * This function first checks if the file can be found in the user's
 * directory. If it can not, it checks the relevant game directory
 * (data, music, lib, etc)
 *
 * \param str1 The first part of the string, assuming the file can't be found in user_dir (eg. "C:\Program Files\KQ\")
 * \param str2 The second part of the string (eg. "scripts")
 * \param file The filename
 * \returns the combined path
 */
const string get_resource_file_path(const string str1, const string str2, const string file)
{
	FILE* fp = nullptr;

	const string userDirFound = CombinePaths(3, user_dir, str2, file);
	fp = fopen(userDirFound.c_str(), "r");
	if (fp)
	{
		fclose(fp);
		return userDirFound;
	}

	const string customDirFound = CombinePaths(3, str1, str2, file);
	fp = fopen(customDirFound.c_str(), "r");
	if (fp)
	{
		fclose(fp);
		return customDirFound;
	}
	return "";
}

/*! \brief Returns the full path for this lua script.
 *
 * This function first checks if the lua file can be found in the user's directory. If it
 * can't, it checks the relevant game directory (data, music, lib, etc). For each
 * directory, it first checks for a lob file, and then it checks for a lua file. This
 * function is similar to get_resource_file_path(), but takes special considerations for
 * lua files. Whereas get_resource_file_path() takes the full filename (eg. "main.map"),
 * this function takes the filename without extension (eg "main").
 *
 * \param file The filename
 * \returns the combined path
 */
const string get_lua_file_path(const string file)
{
	FILE* fp = nullptr;

	const string userDirLob = CombinePaths(3, user_dir, "scripts", file + ".lob");
	fp = fopen(userDirLob.c_str(), "r");
	if (fp)
	{
		fclose(fp);
		return userDirLob;
	}

	const string userDirLua = CombinePaths(3, user_dir, "scripts", file + ".lua");
	fp = fopen(userDirLua.c_str(), "r");
	if (fp)
	{
		fclose(fp);
		return userDirLua;
	}

	const string gameDirLob = CombinePaths(3, game_dir, "scripts", file + ".lob");
	fp = fopen(gameDirLob.c_str(), "r");
	if (fp)
	{
		fclose(fp);
		return gameDirLob;
	}

	const string gameDirLua = CombinePaths(3, game_dir, "scripts", file + ".lua");
	fp = fopen(gameDirLua.c_str(), "r");
	if (fp)
	{
		fclose(fp);
		return gameDirLua;
	}

	return "";
}

/*! \brief Return the name of 'significant' directories.
 *
 * \param   dir Enumerated constant for directory type  \sa DATA_DIR et al.
 * \param   file File name below that directory.
 * \returns the combined path
 */
const string kqres(eDirectories dir, string file)
{
	HINSTANCE SHFolder;
	SHGETFOLDERPATH SHGetFolderPath;
	char* home = nullptr;

	if (!init_path)
	{
		WCHAR tmp[MAX_PATH];
		home = NULL;
		/* Get home directory; this bit originally written by SH */
		SHFolder = LoadLibrary("shfolder.dll");
		if (SHFolder != NULL)
		{
			SHGetFolderPath = (SHGETFOLDERPATH)GetProcAddress(SHFolder, "SHGetFolderPathW");
			if (SHGetFolderPath != NULL)
			{
				/* Get the "Application Data" folder for the current user */
				if (SHGetFolderPath(NULL, CSIDL_APPDATA | CSIDL_FLAG_CREATE, NULL, SHGFP_TYPE_CURRENT, tmp) == S_OK)
				{
					home = uconvert((const char*)tmp, U_UNICODE, NULL, U_UTF8, 0);
				}
			}
			FreeLibrary(SHFolder);
		}

		/* Do not get fooled by a corrupted $HOME */
		if (home != NULL && strlen(home) < MAX_PATH)
		{
			sprintf(user_dir, "%s\\KQ", home);
			/* Always try to make the directory, just to be sure. */
			_mkdir(user_dir);
		}
		else
		{
			strcpy(user_dir, ".");
		}
		/* Now the data directory */
		strcpy(game_dir, ".");
		init_path = 1;
	}

	switch (dir)
	{
	case DATA_DIR:
		return get_resource_file_path(game_dir, "data", file);
		break;
	case MAP_DIR:
		return get_resource_file_path(game_dir, "maps", file);
		break;
	case SAVE_DIR:
	case SETTINGS_DIR:
		return CombinePaths(2, user_dir, file);
		break;
	case MUSIC_DIR:
		return get_resource_file_path(game_dir, "music", file);
		break;
	case SCRIPT_DIR:
		return get_lua_file_path(file);
		break;
	default:
		return NULL;
	}
}
