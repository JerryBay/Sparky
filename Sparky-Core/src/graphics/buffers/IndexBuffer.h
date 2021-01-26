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
				IndexBuffer(GLushort* data, GLsizei count);

				void bind() const;
				void unbind() const;

				GLuint getCount() const { return m_Count; }
		};
	}
}
