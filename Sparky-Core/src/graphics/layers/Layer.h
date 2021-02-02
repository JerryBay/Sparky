#pragma once
#include <graphics/Renderable2D.h>
#include <graphics/Renderer2D.h>

namespace Sparky
{
	namespace Graphics
	{
		class Layer
		{
		protected:
			Renderer2D* m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader* m_Shader;
			Maths::Mat4 m_ProjectionMatrix;
		public:
			virtual ~Layer();
			virtual void add(Renderable2D* renderable);
			virtual void render();
		protected:
			Layer(Renderer2D* renderer,Shader* shader,Maths::Mat4 projectionMatrix);
		};
	}
}