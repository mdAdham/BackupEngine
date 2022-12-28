#include "enpch.h"
#include "Application.h"
#include "Log.h"
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
		WindowResizeEvent e(1200, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			EN_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			EN_TRACE(e);
		}

		while (true);
	}
}