#pragma once

#ifdef EN_PLATFORM_WINDOWS

extern BEngine::Application* BEngine::CreateApplication();

int main(int argc, char** argv)
{
	BEngine::Log::Init();

	EN_CORE_WARN("Initialized Log!");
	EN_TRACE("Initialized Log!");

	auto app = BEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // EN_PLATFORM_WINDOWS
