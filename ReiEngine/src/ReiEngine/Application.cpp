#include "reipch.h"
#include "Application.h"

namespace ReiEngine 
{

	Application::Application()
	{
		m_Window = new Window(1600, 900);
	}

	Application::~Application()
	{
		delete m_Window;
	}

	void Application::Run() 
	{
		while (true) 
		{
			std::cin.get();
		}
	}

}
