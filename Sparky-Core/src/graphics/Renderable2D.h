#pragma once

#include <graphics/buffers/BuffersH.h>
#include "Shader.h"
#include <maths/MathsH.h>

namespace Sparky
{
	namespace Graphics
	{
		struct VertexData
		{
			Maths::Vec3 vertex;
			Maths::Vec4 colors;
		};

		class Renderable2D
		{
		protected:
			Maths::Vec3 m_Position;
			Maths::Vec2 m_Size;
			Maths::Vec4 m_Color;


		public:
			Renderable2D(Maths::Vec3 position, Maths::Vec2 size, Maths::Vec4 color)
				:m_Position(position), m_Size(size), m_Color(color)
			{

			}

			virtual ~Renderable2D() { }


			inline const Maths::Vec3& getPosition() const { return m_Position; }
			inline const Maths::Vec2& getSize() const { return m_Size; }
			inline const Maths::Vec4& getColor() const { return m_Color; }
		};
	}
}