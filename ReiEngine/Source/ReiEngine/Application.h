#pragma once

#include "Window.h"

namespace ReiEngine {

	class Application
	{
	public:
		Application();
		virtual ~Application();	

		void Run();

	private:
		Window* m_Window;
	};

}
