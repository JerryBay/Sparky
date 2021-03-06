#pragma once
#include "Renderer2D.h"
#include "Renderable2D.h"
#include <deque>
#include <graphics/buffers/BuffersH.h>

namespace Sparky
{
	namespace Graphics 
	{
#define RENDERER_MAX_SPRITES 1000000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)
#define RENDERER_SPRITE_SIZE RENDERER_VERTEX_SIZE*4 
#define RENDERER_BUFFER_SIZE RENDERER_VERTEX_SIZE*RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE RENDERER_MAX_SPRITES*6

#define SHADER_VERTEX_INDEX 0
#define SHADER_UV_INDEX 1
#define SHADER_COLOR_INDEX 2

		class BatchRenderer2D:public Renderer2D
		{
		private:
			GLuint m_VAO;
			GLuint m_VBO;
			IndexBuffer* m_IBO;
			GLsizei m_IndexCount;
			VertexData* m_Buffer;
		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void begin() override;
			void end()override;
			void submit(const Renderable2D* renderable) override;
			void flush() override;
		private:
			void init();
		};
	}
}

