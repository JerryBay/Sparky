#include "Static_Sprite.h"

namespace Sparky
{
	namespace Graphics
	{
		Static_Sprite::Static_Sprite(float x,float y,float width,float height,const Maths::Vec4& color,Shader& shader)
			:Renderable2D(Maths::Vec3(x,y,0),Maths::Vec2(width,height),color),m_Shader(shader)
		{
			m_VertexArray = new VertexArray();
			GLfloat vertices[] =
			{
				0,0,0,
				0,height,0,
				width,height,0,
				width,0,0
			};

			GLfloat colors[] =
			{
				color.x,color.y,color.z,color.w,
				color.x,color.y,color.z,color.w,
				color.x,color.y,color.z,color.w,
				color.x,color.y,color.z,color.w
			};

			m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] =
			{
				0,1,2,
				2,3,0
			};
			m_IndexBuffer = new IndexBuffer(indices, 6);
		}

		Static_Sprite::~Static_Sprite()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}
	}
}