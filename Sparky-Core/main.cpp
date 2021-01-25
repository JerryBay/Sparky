#include "Sparky.h"


int main()
{
	using namespace Sparky::Graphics;
	using namespace Sparky::Maths;
	Window win("window",960,540);
	glClearColor(0.2f,0.1f,0.1f,0.1f);

	Vec2 v(1.0f, 2.0f);
	v.add(Vec2(5.0f, 6.0f));
	std::cout << v << std::endl;

	Mat4 position = Mat4::translation(Vec3(2, 3, 4));
	position *= Mat4::identity();

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
#if 0		
		double x, y;
		Window::getMousePosition(x, y);
		std::cout << x << "," << y << std::endl;
#endif // 0


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