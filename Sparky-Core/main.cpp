#include "Sparky.h"


int main()
{
	using namespace Sparky;
	using namespace Sparky::Graphics;
	using namespace Sparky::Maths;
	Window win("Sparky", 960, 540);
	glClearColor(0.0f, 0.0f, 0.0f,1.0f);

#if 0
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
#else
	GLfloat vertices[] =
	{
		0,0,0,
		8,0,0,
		0,3,0,
		8,0,0
	};

	GLushort indices[] =
	{
		0,1,2,
		2,3,0
	};

	GLfloat colorsA[] =
	{
		1,0,1,1,
		1,0,1,1,
		1,0,1,1,
		1,0,1,1
	};

	GLfloat colorsB[] =
	{
		0.2f, 0.5f, 0.8f, 1.0f,
		0.2f, 0.5f, 0.8f, 1.0f,
		0.2f, 0.5f, 0.8f, 1.0f,
		0.2f, 0.5f, 0.8f, 1.0f
	};

	VertexArray sprite1,sprite2;
	Buffer* vbo = new Buffer(vertices,4*3,3);
	IndexBuffer ibo(indices, 6);

	sprite1.addBuffer(vbo, 0);
	sprite2.addBuffer(vbo, 0);

#endif // 0

	Mat4 ortho = Mat4::orthographic(0.0f,16.0f,0.0f,9.0f,-1.0f,1.0f);

	Shader shader("src/shaders/basic.vert","src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix",ortho);
	shader.setUniform2f("light_pos", Vec2(0.0f, 0.0f));
	shader.setUniform4f("color", Vec4(0.2f, 0.5f, 0.8f, 1.0f));
	shader.setUniformMat4("ml_matrix",Mat4::translation(Vec3(4,3,0)));



	while (!win.closed())
	{
		win.clear();
		double x, y;
		win.getMousePosition(x, y);
		shader.setUniform2f("light_pos", Vec2(x * 16.0f / 960.0f,(9.0f- y * 9.0f / 540.0f)));
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);
#else
		sprite1.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", Mat4::translation(Vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.bind();
		sprite1.unbind();

		sprite2.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", Mat4::translation(Vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.bind();
		sprite2.unbind();
#endif // 0

		win.update();
	}
	//system("pause");
	return 0;
}