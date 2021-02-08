#pragma once
#include <graphics/Renderable2D.h>


namespace Sparky
{
	namespace Graphics
	{
		class Group:public Renderable2D
		{
		private:
			std::vector<Renderable2D*> m_Renderables;
			Maths::Mat4 m_TransformationMatrix;
		public:
			Group(const Maths::Mat4& transform);
		public:
			void submit(Renderer2D* renderer) const override;
			void add(Renderable2D* renderable);
		};
	}
}

