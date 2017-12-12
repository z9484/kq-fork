#include "player.h"

KPlayer kPlayer;

KPlayer::KPlayer()
    : playerName()
    , xp()
    , next()
    , lvl()
    , mrp()
    , hp()
    , mhp()
    , mp()
    , mmp()
{
    for (int& stat : stats)
    {
        stat = 0;
    }
    for (char& re : res)
    {
        re = 0;
    }
    for (unsigned char& st : sts)
    {
        st = 0;
    }
    for (unsigned char& i : eqp)
    {
        i = 0;
    }
    for (unsigned char& spell : spells)
    {
        spell = 0;
    }
    for (unsigned short& i : lup) {
        i = 0;
    }
}

KPlayer::~KPlayer()
{
}
