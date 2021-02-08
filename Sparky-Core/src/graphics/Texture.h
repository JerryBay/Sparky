#pragma once
#include <string>
#include <glew.h>
#include <FreeImage.h>
#include <utils/ImageLoad.h>

namespace Sparky
{
	namespace Graphics
	{
		class Texture
		{
		private:
			std::string m_Filename;
			GLuint m_TID;
			GLsizei m_Width, m_Height;
		public:
			Texture(const std::string& path);
			~Texture();
			void bind() const;
			void unbind() const;

			inline const unsigned int getWidth() { return m_Width; }
			inline const unsigned int getHeight() { return m_Height; }
		private:
			GLuint load();
		};
	}
}