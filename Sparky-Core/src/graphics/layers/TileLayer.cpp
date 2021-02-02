#include "TileLayer.h"

namespace Sparky
{
	namespace Graphics
	{
		TileLayer::~TileLayer()
		{

		}

		TileLayer::TileLayer(Shader* shader)
			:Layer(new BatchRenderer2D(),shader,Maths::Mat4::orthographic(-16.0f,16.0f,-9.0f,9.0f,-1.0f,1.0f))
		{

		}
	}
}