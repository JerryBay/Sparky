#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace Sparky
{
	namespace Maths
	{
		inline float toRadian(float degrees)
		{
			return (float)M_PI / 180.0f;
		}
	}
}