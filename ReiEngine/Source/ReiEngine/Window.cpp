#include "reipch.h"
#include "Window.h"

namespace ReiEngine
{
	Window::Window(int width, int height) : m_Width(width), m_Height(height)
	{
		m_Window = SDL_CreateWindow("ReiEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, 0);
	}

	Window::~Window()
	{
	}
}
