#include "animation.h"
#include "anim_sequence.h"
#include "tmx_animation.h"

void KAnimation::check_animation(int millis, uint16_t* tilex)
{
	for (auto& anim : animations_)
	{
		anim.nexttime_ -= millis;
		
		// If several frames are skipped, this loop ensures that the correct animation
		// tile is rendered.
		while (anim.nexttime_ < 0)
		{
			anim.nexttime_ += anim.current().delay;
			anim.advance();
		}
		tilex[anim.animation_.tilenumber] = anim.current().tile;
	}
}

void KAnimation::add_animation(const KTmxAnimation& base)
{
	animations_.push_back(KAnimSequence(base));
}

void KAnimation::clear_animations()
{
	animations_.clear();
}

// Note: *copy* the base animation into this instance. The base animation
// comes from a tmx_map which may be destroyed.
KAnimation::KAnimSequence::KAnimSequence(const KTmxAnimation& base)
	: animation_(base)
{
	index_ = 0;
	nexttime_ = current().delay;
}

KTmxAnimation::animation_frame KAnimation::KAnimSequence::current() const
{
	return animation_.frames[index_];
}

void KAnimation::KAnimSequence::advance()
{
	if (index_ < animation_.frames.size() - 1)
		if (++index_ >= animation_.frames.size())
		{
			index_ = 0;
		}
}

KAnimation kqAnimation;
