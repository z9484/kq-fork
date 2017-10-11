#pragma once

#include <stdint.h>
#include <vector>
using std::vector;

#include "tmx_animation.h"

class KAnimSequence;
class KAnimation
{
public:
	void check_animation(int millis, uint16_t* tilex);
	void add_animation(const KTmxAnimation& base);
	void clear_animations();

private:
	vector<KAnimSequence> animations;
};

extern KAnimation Animation;
