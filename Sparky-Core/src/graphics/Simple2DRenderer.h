#pragma once

#include <deque>
#include "Renderer2D.h"


namespace Sparky
{
	namespace Graphics
	{
		class Simple2DRenderer:public Renderer2D
		{
		private:
			std::deque<Renderable2D*> m_RenderQueue;
		public:
			virtual void submit(Renderable2D* renderable) override;
			virtual void flush() override;
		};
	}
}