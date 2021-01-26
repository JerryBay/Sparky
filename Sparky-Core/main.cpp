#include "Sparky.h"


int main()
{
	using namespace Sparky;
	using namespace Sparky::Graphics;
	using namespace Sparky::Maths;
	Window win("Sparky", 960, 540);
	glClearColor(0.0f, 0.0f, 0.0f,1.0f);


	GLfloat vertices[] =
	{
		0,0,0,
		12,0,0,
		4,3,0,
		12,6,0,
		12,8,0,
		0,6,0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Mat4 ortho = Mat4::orthographic(0.0f,16.0f,0.0f,9.0f,-1.0f,1.0f);

	Shader shader("src/shaders/basic.vert","src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix",ortho);
	shader.setUniform2f("light_pos", Vec2(0.0f, 0.0f));
	shader.setUniform4f("colour", Vec4(0.2f, 0.5f, 0.8f, 1.0f));
	shader.setUniformMat4("ml_matrix",Mat4::translation(Vec3(3,3,0)));



	while (!win.closed())
	{
		win.clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		win.update();
	}
	//system("pause");
	return 0;
}