#pragma once

#ifdef EN_PLATFORM_WINDOWS

extern BEngine::Application* BEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = BEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // EN_PLATFORM_WINDOWS
