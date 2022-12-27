#include <BackupEngine.h>

class SandBox : public BEngine::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};
BEngine::Application* BEngine::CreateApplication()
{
	return new SandBox();
}