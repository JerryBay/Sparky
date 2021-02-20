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
			Maths::Vec2 uv;
			unsigned int tid;
			unsigned int colors;
		};

		class Renderable2D
		{
		protected:
			Maths::Vec3 m_Position;
			Maths::Vec2 m_Size;
			Maths::Vec4 m_Color;
			std::vector<Maths::Vec2> m_UV;
		protected:
			Renderable2D() 
			{
				setUVDefault();
			}

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
			inline const std::vector<Maths::Vec2>& getUV() const { return m_UV; }
		private:
			void setUVDefault()
			{
				m_UV.push_back(Maths::Vec2(0, 0));
				m_UV.push_back(Maths::Vec2(0, 1));
				m_UV.push_back(Maths::Vec2(1, 1));
				m_UV.push_back(Maths::Vec2(1, 0));
			}
		};
	}
}