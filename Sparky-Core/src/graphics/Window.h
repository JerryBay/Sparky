#pragma once
#include <glew.h>
#include <glfw3.h>


namespace Sparky
{
	namespace Graphics
	{
#define MAX_KEYS 1024
#define MAX_BUTTONS 32
		class Window
		{
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void mouseButton_callback(GLFWwindow* window, int button, int action, int mods);
			friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		private:
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
			bool m_Closed;

			static bool keys[MAX_KEYS];
			static bool mouseButtons[MAX_BUTTONS];
			static double mX, mY;
		public:
			Window(const char* name, int width, int height);
			~Window();

			void update();
			bool closed() const;
			void clear() const;

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }
			
			static bool isKeyPressed(unsigned int keycode);
			static bool isMouseButtonPressed(unsigned int button);
			static void getMousePosition(double& x, double& y);

		private:
			bool init();
		};

		void window_Resize(GLFWwindow* window, int width, int height);
	}
}
