#pragma once

#include "ReiEngine/Renderer/RenderContext.h"

#include "SDL2/SDL.h"

namespace ReiEngine
{
	class OpenGLRenderContext : public RenderContext
	{
	public:
		OpenGLRenderContext(SDL_Window* window);
		~OpenGLRenderContext();

		virtual void Clear() override;
		virtual void SwapBuffers() override; // TODO: Should this be elsewhere?

	private:
		SDL_Window* m_Window;

		SDL_GLContext m_Context;
	};
}