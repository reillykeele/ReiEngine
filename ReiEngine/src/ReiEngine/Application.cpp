#include "reipch.h"
#include "Application.h"

namespace ReiEngine 
{

	Application::Application()
	{
		m_Window = Window::Create();
	}

	Application::~Application()
	{
		delete m_Window;
	}

	void Application::Run() 
	{
		// todo set up a fucking game loop or soemthing
		while (true) 
		{
			std::cin.get();
		}
	}

}
