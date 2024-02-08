#pragma once

#ifdef DOM_PLATFORM_WINDOWS

extern Domension::Application* Domension::CreateApplication();

int main(int argc, char** argv)
{
	Domension::Log::Init();
	DOM_CORE_WARN("Initialized Log!");
	int a = 5;
	DOM_INFO("Hello! Var = {0}", a);

	auto app = Domension::CreateApplication();
	app->Run();
	delete app;
}

#endif 

