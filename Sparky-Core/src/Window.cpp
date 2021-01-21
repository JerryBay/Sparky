#include "Window.h"

namespace Sparky
{
	namespace Graphics
	{
		Window::Window(const char* name, int width, int height)
			:m_Title(name), m_Width(width), m_Height(height)
		{
			if (!Init())
			{
				glfwTerminate();
			}
		}

		Window::~Window()
		{

		}

		void Window::Update()
		{
			glfwPollEvents();
			//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		bool Window::Init()
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
			glfwSetWindowSizeCallback(m_Window, WindowResize);
			return true;
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void WindowResize(GLFWwindow* window,int width,int height)
		{
			glViewport(0, 0, width, height);
		}
	}
}