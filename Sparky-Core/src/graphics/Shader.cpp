#include <string>
#include <iostream>
#include <vector>
#include <utils/FileUtils.h>
#include "Shader.h"

namespace Sparky
{
	namespace Graphics
	{
		Shader::Shader(const char* vertPath, const char* fragPath)
			:m_VertPath(vertPath),m_FragPath(fragPath)
		{
			m_ShaderID = load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_ShaderID);
		}

		GLint Shader::getUniformLocation(const GLchar* name)
		{
			return glGetUniformLocation(m_ShaderID, name);
		}

		void Shader::setUniform1f(const GLchar* name, float value)
		{
			glUniform1f(getUniformLocation(name), value);
		}

		void Shader::setUniform1i(const GLchar* name, int value)
		{
			glUniform1i(getUniformLocation(name), value);
		}

		void Shader::setUniform2f(const GLchar* name, const Maths::Vec2& vector)
		{
			glUniform2f(getUniformLocation(name), vector.x,vector.y);
		}

		void Shader::setUniform3f(const GLchar* name, const Maths::Vec3& vector)
		{
			glUniform3f(getUniformLocation(name), vector.x, vector.y,vector.z);
		}

		void Shader::setUniform4f(const GLchar* name, const Maths::Vec4& vector)
		{
			glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z,vector.w);
		}

		void Shader::setUniformMat4(const GLchar* name, const Maths::Mat4& matrix)
		{
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
		}

		GLuint Shader::load()
		{
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSourceString = FileUtil::read_file(m_VertPath);
			std::string fragSourceString = FileUtil::read_file(m_FragPath);
			const char* vertSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();

			GLint compiled;
			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &compiled);
			if (compiled ==GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout <<"Failed compile vertex shader! " << std::endl << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &compiled);
			if (compiled == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "Failed compile fragment shader! " << std::endl << &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			GLuint program = glCreateProgram();
			glAttachShader(program, vertex);
			glAttachShader(program, fragment);
			glLinkProgram(program);
			glValidateProgram(program);
			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		void Shader::enable() const
		{
			glUseProgram(m_ShaderID);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}
	}
}
