#pragma once

#include <SDL.h>

namespace ReiEngine
{
	class Window
	{
	public:
		Window(int width, int height);
		virtual ~Window();

		inline int GetWidth() { return m_Width; }
		inline int GetHeight() { return m_Height; }

	private:
		int m_Width;
		int m_Height;

		SDL_Window* m_Window;
	};
}
