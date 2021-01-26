#include <iostream>
#include "Window.h"

namespace Sparky
{
	namespace Graphics
	{
		bool Window::keys[MAX_KEYS];
		bool Window::mouseButtons[MAX_BUTTONS];
		double Window::mX;
		double Window::mY;

		void window_Resize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->keys[key] = action != GLFW_RELEASE;
		}

		void mouseButton_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mouseButtons[button]=action!= GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mX = xpos;
			win->mY = ypos;
		}

		Window::Window(const char* name, int width, int height)
			:m_Title(name), m_Width(width), m_Height(height)
		{
			if (!init())
			{
				glfwTerminate();
			}
			for (int i = 0; i < MAX_KEYS; i++)
			{
				keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				mouseButtons[i] = false;
			}
		}

		Window::~Window()
		{

		}

		void Window::update()
		{
			glfwPollEvents();
			//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "Failed to create window!";
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, window_Resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouseButton_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);

			std::cout << "OpenGL version:OpenGL " << glGetString(GL_VERSION) << std::endl;

			if (glewInit()!=GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
			}
			return true;
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::isKeyPressed(unsigned int keycode)
		{
			if (keycode>=MAX_KEYS)
			{
				return false;
			}
			return keys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button)
		{
			if (button>=MAX_BUTTONS)
			{
				return false;
			}
			return mouseButtons[button];
		}

		void Window::getMousePosition(double& x, double& y)
		{
			x = mX;
			y = mY;
		}
	}
}