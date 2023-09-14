#pragma once

#include "ReiEngine/Window.h"

#include "SDL2/SDL.h"

namespace ReiEngine
{
	class SDLWindow : public Window
	{
	public:
		SDLWindow();
		virtual ~SDLWindow();

		virtual void Show() override;
		virtual void Hide() override;
		
		virtual bool IsVsync() override;
		virtual void SetVsync(bool useVsync) override;
		
		virtual void Swap() override;
	
	private:
		SDL_Window* m_Window;

		uint32_t m_Width;
		uint32_t m_Height;
	};
}