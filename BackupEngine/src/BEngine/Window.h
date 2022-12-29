#pragma once

#include "enpch.h"

#include "BEngine/Core.h"
#include "BEngine/Events/Event.h"

namespace BEngine {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "BackupEngine",
			unsigned int width = 1200,
			unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{
		}
	};

	class BENGINE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() { }

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}