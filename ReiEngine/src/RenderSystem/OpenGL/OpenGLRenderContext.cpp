#include "reipch.h"
#include "OpenGLRenderContext.h"

#include "glad/glad.h"

namespace ReiEngine
{
	OpenGLRenderContext::OpenGLRenderContext(SDL_Window* window) : m_Window(window)
	{
		m_Context = SDL_GL_CreateContext(window);

		int version = gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

		std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
		std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
		std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
	}

	OpenGLRenderContext::~OpenGLRenderContext()
	{
		std::cout << "~OpenGLRenderContext" << std::endl;
		SDL_GL_DeleteContext(m_Context);
	}

	void OpenGLRenderContext::Clear()
	{
		// TODO Clear color
		glClearColor(0.7f, 0.9f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void OpenGLRenderContext::SwapBuffers()
	{
		SDL_GL_SwapWindow(m_Window);
	}

}