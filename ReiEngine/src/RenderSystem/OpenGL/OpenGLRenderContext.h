#pragma once

#include "ReiEngine/Renderer/RenderContext.h"

#include "SDL2/SDL.h"

namespace ReiEngine
{

	class OpenGLRenderContext : public RenderContext
	{
	public:
		OpenGLRenderContext();
		~OpenGLRenderContext();

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		SDL_Window* m_Window;

		SDL_GLContext* m_Context;
	};
}