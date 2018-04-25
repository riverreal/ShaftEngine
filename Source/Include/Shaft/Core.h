#pragma once

#define SHAFT_EDITOR_ENABLED true
#define DEFAULT_SCREEN_WIDTH 1280
#define DEFAULT_SCREEN_HEIGHT 720
#define ACTOR_RESERVE_COUNT 1000

//File reading paths will be different
//Set to true for build a true release build
#define SE_BUILD false

#ifdef _WIN32
#define PLATFORM_WINDOWS 1
#define WINDOW_TYPE_GLFW 1
#define WINDOW_TYPE_WINAPI 0
#elif __APPLE__
#define PLATFORM_MACOS 1
#define WINDOW_TYPE_GLFW 1
#elif __linux__
#define PLATFORM_LINUX 1
#define WINDOW_TYPE_GLFW 1
#endif

//Standard
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
#include <memory>

//Library
#include <entityx/entityx.hh>
#include <bx/bx.h>
#include <bgfx/bgfx.h>

#if WINDOW_TYPE_GLFW
	#include<GLFW/glfw3.h>

#if WINDOW_TYPE_GLFW
	#if BX_PLATFORM_WINDOWS
		#define GLFW_EXPOSE_NATIVE_WIN32
	#elif BX_PLATFORM_OSX
		#define GLFW_EXPOSE_NATIVE_COCOA
	#elif BX_PLATFORM_LINUX || BX_PLATFORM_BSD
		#define GLFW_EXPOSE_NATIVE_X11
	#endif
#endif

#endif// WINDOW_TYPE_GLFW

#if WINDOW_TYPE_WINAPI
#include <Windows.h>
#endif // WINDOW_TYPE_WINAPI

//Fix min, max Windows.h macro incompantibility with std::min, max
#if BX_PLATFORM_WINDOWS
	#undef min
	#undef max
#endif

//Platform Specific types
#include "../../Engine/System/Platform/Platform.h"
//Shaft types
#include "../../Engine/System/ShaftTypes.h"