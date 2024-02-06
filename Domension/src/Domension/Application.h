#pragma once

#include "Core.h"

namespace Domension
{
	class DOM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in a client
	Application* CreateApplication();
}


