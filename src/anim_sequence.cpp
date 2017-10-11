#include <vector>
using std::vector;

#include "anim_sequence.h"
#include "tmx_animation.h"

// Note: *copy* the base animation into this instance. The base animation
// comes from a tmx_map which may be destroyed.
KAnimSequence::KAnimSequence(const KTmxAnimation& base)
	: animation(base)
{
	index = 0;
	nexttime = current().delay;
}

// Move constructor to aid efficiency
KAnimSequence::KAnimSequence(KAnimSequence&& other)
	: animation(other.animation)
{
	nexttime = other.nexttime;
	index = other.index;
}

const KTmxAnimation::animation_frame& KAnimSequence::current()
{
	return animation.frames[index];
}

void KAnimSequence::advance()
{
	if (++index >= animation.frames.size())
	{
		index = 0;
	}
}
