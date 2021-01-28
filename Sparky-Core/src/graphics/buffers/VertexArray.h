#pragma once
#include <glew.h>
#include <vector>
#include "Buffer.h"

namespace Sparky
{
	namespace Graphics
	{
		class VertexArray
		{
		private:
			GLuint m_ArrayID;
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer* buffer, GLuint index);
			void bind() const;
			void unbind() const;
		};
	}
}
