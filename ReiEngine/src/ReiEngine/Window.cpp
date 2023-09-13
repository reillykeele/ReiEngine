#include "reipch.h"
#include "Window.h"

#include "SDL2/SDL.h"
#include "glad/glad.h"

namespace ReiEngine
{
	Window::Window(int width, int height) : m_Width(width), m_Height(height)
	{		
		SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		SDL_Window* window = SDL_CreateWindow("ReiEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		SDL_GLContext context = SDL_GL_CreateContext(window);		

		int version = gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress);

		std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
		std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
		std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;

		// use vsync TODO: add a flag or something
		SDL_GL_SetSwapInterval(1);

		// game loop
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

			glClearColor(0.7f, 0.9f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

			SDL_GL_SwapWindow(window);
			SDL_Delay(1);
		}

		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	Window::~Window()
	{
	}
}
