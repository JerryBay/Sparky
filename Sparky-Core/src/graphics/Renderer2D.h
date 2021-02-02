#pragma once
#include <glew.h>
#include <maths/MathsH.h>
#include "Renderable2D.h"
#include "Static_Sprite.h"

namespace Sparky
{
	namespace Graphics
	{
		class Renderer2D
		{
		public:
			virtual void begin()=0;
			virtual void end()=0;
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};
	}
}