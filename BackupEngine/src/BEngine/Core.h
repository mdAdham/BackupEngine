#pragma once

#ifdef EN_PLATFORM_WINDOWS
	#ifdef EN_BUILD_DLL
		#define BENGINE_API __declspec(dllexport)
	#else
		#define BENGINE_API __declspec(dllimport)
	#endif // EN_BUILD_DLL
#else
	#error BEngine only supports window!
#endif // EN_PLATFORM_WINDOWS
