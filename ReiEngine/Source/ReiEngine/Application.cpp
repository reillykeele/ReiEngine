#include "Application.h"

#include <iostream>

namespace ReiEngine {

	Application::Application()
	{
		// do stuff!
		std::cout << "Creating Application" << std::endl;
	}

	Application::~Application()
	{
		
		std::cout << "Destroying Application" << std::endl;// die
	}

}
