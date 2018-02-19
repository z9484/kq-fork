#include "animation.h"
#include "anim_sequence.h"

void KAnimation::check_animation(int millis, uint16_t* tilex)
{
	for (auto& a : animations)
	{
		a.nexttime -= millis;
		while (a.nexttime < 0)
		{
			a.nexttime += a.current().delay;
			a.advance();
		}
		tilex[a.animation.tilenumber] = a.current().tile;
	}
}

void KAnimation::add_animation(const KTmxAnimation& base)
{
	animations.push_back(KAnimSequence(base));
}

void KAnimation::clear_animations()
{
	animations.clear();
}

KAnimation kqAnimation;
