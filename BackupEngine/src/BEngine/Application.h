#pragma once

#include "Core.h"

namespace BEngine {

	class BENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be Define in Client
	Application* CreateApplication();
}