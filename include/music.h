#pragma once

#include <string>
using std::string;

/* ML: include aldumb.h here, because other modules really don't know that
   we are using dumb, and it doesn't make sense to have to include aldumb
   individually */

class KMusic
{
public:
  void init_music(void);
  void shutdown_music(void);
  void poll_music(void);

  void set_music_volume(float volume);

  void play_music(const string &music_name, long position);
  void pause_music(void);
  void resume_music(void);
  void stop_music(void);
};

extern KMusic Music;
