#pragma once

#include "animation.h"
#include "tiledmap.h"

class KAnimSequence
{
public:
	KAnimSequence(const KTmxAnimation &);
	KAnimSequence(KAnimSequence &&);

	const KTmxAnimation::animation_frame &current();

	void advance();

public:
	int nexttime;
	size_t index;
	const KTmxAnimation animation;
};

extern KAnimSequence AnimSequence;
