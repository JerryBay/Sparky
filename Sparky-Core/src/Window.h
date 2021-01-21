#pragma once
#include <glfw3.h>
#include <iostream>

namespace Sparky
{
	namespace Graphics
	{
		class Window
		{
		private:
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
		public:
			Window(const char* name, int width, int height);
			~Window();
			void Update();
			bool Closed() const;
			void Clear() const;

			inline int GetWidth() const { return m_Width; }
			inline int GetHeight() const { return m_Height; }

		private:
			bool Init();

		};

		void WindowResize(GLFWwindow*, int, int);
	}
}
