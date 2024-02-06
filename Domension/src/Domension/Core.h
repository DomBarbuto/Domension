#pragma once

#ifdef DOM_PLATFORM_WINDOWS
	#ifdef DOM_BUILD_DLL
		#define DOM_API __declspec(dllexport)
	#else
		#define DOM_API __declspec(dllimport)
	#endif
#else
	#error Domension only supports Windows!
#endif