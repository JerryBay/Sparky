#include "Simple2DRenderer.h"

namespace Sparky
{
	namespace Graphics
	{
		void Simple2DRenderer::submit(const Renderable2D* renderable)
		{
			m_RenderQueue.push_back(renderable);
		}

		void Simple2DRenderer::flush()
		{
			Static_Sprite* renderable;
			while (!m_RenderQueue.empty())
			{
				renderable = (Static_Sprite*)m_RenderQueue.front();
				renderable->getVAO()->bind();
				renderable->getIBO()->bind();

				renderable->getShader().setUniformMat4("ml_matrix", Maths::Mat4::translation(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

				renderable->getIBO()->unbind();
				renderable->getVAO()->unbind();

				m_RenderQueue.pop_front();
			}
		}
	}
}
