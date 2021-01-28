#pragma once
#include <glew.h>

namespace Sparky
{
	namespace Graphics
	{
		class IndexBuffer
		{
		private:
			GLuint m_BufferID;
			GLuint m_Count;
		public:
			IndexBuffer(GLuint* data, GLsizei count);
			IndexBuffer(GLushort* data, GLsizei count);
			~IndexBuffer();
			void bind() const;
			void unbind() const;

			GLuint getCount() const { return m_Count; }
		};
	}
}
