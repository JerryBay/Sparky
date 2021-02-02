#pragma once
#include "Layer.h"
#include <graphics/BatchRenderer2D.h>

namespace Sparky
{
	namespace Graphics
	{
		class TileLayer:public Layer
		{
		public:
			TileLayer(Shader* shader);
			~TileLayer();
		};
	}
}