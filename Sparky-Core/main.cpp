#include "Sparky.h"


int main()
{
	using namespace Sparky::Graphics;
	Window win("window",960,540);
	glClearColor(0.2f,0.1f,0.1f,0.1f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!win.closed())
	{
		win.clear();
		if (Window::isKeyPressed(GLFW_KEY_A))
		{
			std::cout << "PRESSED!" << std::endl;
		}

		if (Window::isMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
		{
			std::cout << "MOUSEBUTTON!" << std::endl;
		}
		double x, y;
		Window::getMousePosition(x, y);
		std::cout << x << "," << y << std::endl;
#if 1
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f,-0.5f);
		glVertex2f(0.0f,0.5f);
		glVertex2f(0.5f,-0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

#endif
		win.update();
	}
	//system("pause");
	return 0;
}