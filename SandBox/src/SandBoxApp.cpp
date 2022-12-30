#include <BackupEngine.h>

class ExampleLayer : public BEngine::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		EN_INFO("ExampleLayer::Update");
	}

	void OnEvent(BEngine::Event& event) override
	{
		EN_TRACE("{0}", event);
	}
};

class SandBox : public BEngine::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer);
	}

	~SandBox()
	{

	}
};
BEngine::Application* BEngine::CreateApplication()
{
	return new SandBox();
}