#pragma once

#include <graphics/buffers/BuffersH.h>
#include "Shader.h"
#include <maths/MathsH.h>
#include <graphics/Renderer2D.h>

namespace Sparky
{
	namespace Graphics
	{
		struct VertexData
		{
			Maths::Vec3 vertex;
			unsigned int colors;
		};

		class Renderable2D
		{
		protected:
			Maths::Vec3 m_Position;
			Maths::Vec2 m_Size;
			Maths::Vec4 m_Color;
		protected:
			Renderable2D() {}

		public:
			Renderable2D(Maths::Vec3 position, Maths::Vec2 size, Maths::Vec4 color)
				:m_Position(position), m_Size(size), m_Color(color)
			{

			}

			virtual ~Renderable2D() { }

			virtual void submit(Renderer2D* renderer) const
			{
				renderer->submit(this);
			}

			inline const Maths::Vec3& getPosition() const { return m_Position; }
			inline const Maths::Vec2& getSize() const { return m_Size; }
			inline const Maths::Vec4& getColor() const { return m_Color; }
		};
	}
}