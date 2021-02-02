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
		protected:
			std::vector<Maths::Mat4> m_TransformationStack;
			Maths::Mat4* m_TransformationBack;
		protected:
			Renderer2D()
			{
				m_TransformationStack.push_back(Maths::Mat4::identity());
				m_TransformationBack = &m_TransformationStack.back();
			}
		public:
			void push(const Maths::Mat4& matrix, bool override = false)
			{
				if (override)
				{
					m_TransformationStack.push_back(matrix);
				}
				else
				{
					m_TransformationStack.push_back(m_TransformationStack.back() * matrix);
				}
				m_TransformationBack = &m_TransformationStack.back();

			}
			void pop()
			{
				if (m_TransformationStack.size() > 1)
				{
					m_TransformationStack.pop_back();
				}

				m_TransformationBack = &m_TransformationStack.back();
			}
			virtual void begin() = 0;
			virtual void end() = 0;
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};
	}
}