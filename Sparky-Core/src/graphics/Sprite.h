#pragma once
#include "Renderable2D.h"

namespace Sparky
{
	namespace Graphics
	{
		class Sprite:public Renderable2D
		{
		private:

		public:
			Sprite(float x, float y, float width, float height, const Maths::Vec4& color);
		};
	}
}