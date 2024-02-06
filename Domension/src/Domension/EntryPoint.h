#pragma once

#ifdef DOM_PLATFORM_WINDOWS

extern Domension::Application* Domension::CreateApplication();

int main(int argc, char** argv)
{
	printf("Domension Engine");
	auto app = Domension::CreateApplication();
	app->Run();
	delete app;
}

#endif 

