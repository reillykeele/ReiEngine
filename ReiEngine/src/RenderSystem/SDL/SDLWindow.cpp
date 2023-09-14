#include "reipch.h"
#include "SDLWindow.h"

#include "RenderSystem/OpenGL/OpenGLRenderContext.h"

namespace ReiEngine
{
	SDLWindow::SDLWindow() : m_Width(800), m_Height(600)
	{
		SDL_Init(SDL_INIT_VIDEO);

		// TODO: Where should this go? here ?
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		m_Window = SDL_CreateWindow("ReiEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		
		OpenGLRenderContext context = OpenGLRenderContext(m_Window);

		// TODO: not currently setting this lol
		SetVsync(true);

		// game loop ? uuuhhhh 
		int exit = 0;
		while (!exit)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					exit = 1;
					break;
				case SDL_KEYUP:
					if (event.key.keysym.sym == SDLK_ESCAPE)
						exit = 1;
					break;
				default:
					break;
				}
			}

			// render here ?

			context.Clear();
			context.SwapBuffers();
			
			SDL_Delay(1);
		}
		
		SDL_Quit();
	}

	SDLWindow::~SDLWindow()
	{
		std::cout << "~SDLWindow" << std::endl;
		SDL_Quit();
	}

	void SDLWindow::Show()
	{
		SDL_ShowWindow(m_Window);
	}

	void SDLWindow::Hide()
	{
		SDL_HideWindow(m_Window);
	}

	bool SDLWindow::IsVsync()
	{
		return SDL_GL_GetSwapInterval();
	}

	void SDLWindow::SetVsync(bool useVsync)
	{
		SDL_GL_SetSwapInterval(useVsync ? 1 : 0);
	}

	void SDLWindow::Swap()
	{
		// should the window even swap?
		// should it delegate to the render context? 
	}
}