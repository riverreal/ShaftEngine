#pragma once

#define DEFAULT_SCREEN_WIDTH 1280
#define DEFAULT_SCREEN_HEIGHT 720

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>
#include <memory>

#ifdef _WIN32
#define PLATFORM_WINDOWS 1
#define WINDOW_TYPE_GLFW 1
//#define WINDOW_TYPE_WINAPI
#elif __APPLE__
#define PLATFORM_MACOS 1
#define WINDOW_TYPE_GLFW 1
#elif __linux__
#define PLATFORM_LINUX 1
#define WINDOW_TYPE_GLFW 1
#endif

#include <bx/bx.h>
#include <bgfx/bgfx.h>

#ifdef WINDOW_TYPE_GLFW
#include<GLFW/glfw3.h>

#if BX_PLATFORM_WINDOWS
	#define GLFW_EXPOSE_NATIVE_WIN32
#elif BX_PLATFORM_OSX
	#define GLFW_EXPOSE_NATIVE_COCOA
#elif BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	#define GLFW_EXPOSE_NATIVE_X11
#endif

#endif// WINDOW_TYPE_GLFW

#ifdef WINDOW_TYPE_WINAPI
#include <Windows.h>
#endif // WINDOW_TYPE_WINAPI

#undef min
#undef max

#include "System/Platform/Platform.h"