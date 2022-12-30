#pragma once

#include "Core.h"

#include "Window.h"
#include "BEngine/LayerStack.h"
#include "BEngine/Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace BEngine {

	class BENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be Define in Client
	Application* CreateApplication();
}