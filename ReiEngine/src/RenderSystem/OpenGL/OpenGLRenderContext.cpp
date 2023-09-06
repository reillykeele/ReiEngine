#include "reipch.h"
#include "OpenGLRenderContext.h"

namespace ReiEngine
{
	OpenGLRenderContext::OpenGLRenderContext()
	{
		SDL_GL_MakeCurrent(m_Window, m_Context);
	}

	OpenGLRenderContext::~OpenGLRenderContext()
	{
		SDL_GL_DeleteContext(m_Context);
	}

	void OpenGLRenderContext::Init()
	{	
	}	

	void OpenGLRenderContext::SwapBuffers()
	{
	}

}