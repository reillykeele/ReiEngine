#include "reipch.h"
#include "Window.h"

#include "RenderSystem/SDL/SDLWindow.h"

namespace ReiEngine
{	
	Window* Window::Create()
	{
		Window* window = new SDLWindow();

		return window;
	}
}