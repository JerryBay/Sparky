#pragma once
#include <glew.h>
#include <maths/MathsH.h>

namespace Sparky
{
	namespace Graphics
	{
		class Shader
		{
		public:
			GLuint m_ShaderID;
			const char* m_VertPath;
			const char* m_FragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			GLint getUniformLocation(const GLchar* name);

			void setUniform1f(const GLchar* name,float value);
			void setUniform1i(const GLchar* name, int value);
			void setUniform2f(const GLchar* name, const Maths::Vec2& vector);
			void setUniform3f(const GLchar* name, const Maths::Vec3& vector);
			void setUniform4f(const GLchar* name, const Maths::Vec4& vector);
			void setUniformMat4(const GLchar* name,const Maths::Mat4& matrix);

			void enable() const;
			void disable() const;
		private:
			GLuint load();
		};
	}
}

