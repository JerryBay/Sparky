#include "Sparky.h"
#include <time.h>



int main()
{
	using namespace Sparky;
	using namespace Sparky::Graphics;
	using namespace Sparky::Maths;

	Mat4 m = Mat4::translation(Vec3(1, 1, 1));
	m *= Mat4::translation(Vec3(5, 5, 5));
	std::cout << m << std::endl;

	Window win("Sparky", 960, 540);
	glClearColor(0.0f, 0.0f, 0.0f,1.0f);

	Mat4 ortho = Mat4::orthographic(0.0f,16.0f,0.0f,9.0f,-1.0f,1.0f);

	Shader* shader=new Shader("src/shaders/basic.vert","src/shaders/basic.frag");
	shader->enable();
	shader->setUniformMat4("pr_matrix",ortho);

	TileLayer layer(shader);
	layer.add(new Sprite(0, 0, 2, 2, Maths::Vec4(0.8f, 0.2f, 0.8f, 1.0f)));

	std::vector<Renderable2D*> sprites;

	srand(time(NULL));

	BatchRenderer2D renderer;

	for (float y = -0.9f; y < 9.0f; y+=0.1f)
	{
		for (float x = -16.0f; x < 16.0f; x+=0.1f)
		{
			layer.add(new Sprite(x, y, 0.9f, 0.9f, Maths::Vec4(rand()%1000/1000.0f, 0, 1, 1)));
		}
	}

	shader->setUniform2f("light_pos", Vec2(0.0f, 0.0f));
	shader->setUniform4f("color", Vec4(0.2f, 0.5f, 0.8f, 1.0f));

	Timer time;
	float timer=0;
	unsigned int frames = 0;

	while (!win.closed())
	{
		win.clear();
		double x, y;
		win.getMousePosition(x, y);
		shader->setUniform2f("light_pos", Vec2(x * 32.0f / 960.0f-16.0f,(9.0f- y * 18.0f / 540.0f)));

		layer.render();

		win.update();
		frames++;

		if (time.elapsed()-timer>1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	//system("pause");
	return 0;
}