#pragma once

/*
	Checking which platform we are on
*/ 
#ifdef _WIN32
	#ifdef _WIN64
		#define FLIP_WINDOWS
	#else
		#error "32-bit systems are outdated..."	
	#endif

#elif defined(__unix__) || defined(__linux__)
	#define FLIP_LINUX

#elif defined(__APPLE__) || defined(__MACH__)
	#define FLIP_MAC
	#error "Is not supported..."

#else
	#error "Unknown platform... What are you?"

#endif

/*
	Include platform specific files
*/
#ifdef FLIP_WINDOWS
	#define VC_EXTRALEAN
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>

	// GLFW specific
	#define GLFW_EXPOSE_NATIVE_WIN32

#endif

/*
	Defines the Graphics API
*/
#define FLIP_VULCAN
//#define FLIP_D3D11 - Maybe later
