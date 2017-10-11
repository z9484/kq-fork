#pragma once

enum eTransitionFade {
  TRANS_FADE_IN = 1,
  TRANS_FADE_OUT = 2,
  TRANS_FADE_WHITE = 3,

  NUM_TRANSITIONS
};

void do_transition(eTransitionFade, int);
