#include "Domension.h"

class Sandbox : public Domension::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Domension::Application* Domension::CreateApplication()
{
	return new Sandbox();
}
