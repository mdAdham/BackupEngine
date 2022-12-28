#include "Application.h"
#include<iostream>

namespace BEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			if (std::cin.get())
				break;
		}
	}
}