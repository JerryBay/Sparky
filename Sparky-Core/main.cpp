#include "Sparky.h"

int main()
{
	using namespace Sparky::Graphics;
	Window win("window",960,540);
	glClearColor(0.2,0.1,0.1,0.1);

	while (!win.Closed())
	{
		win.Clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f,-0.5f);
		glVertex2f(0.0f,0.5f);
		glVertex2f(0.5f,-0.5f);
		glEnd();
		win.Update();
	}
	//system("pause");
	return 0;
}