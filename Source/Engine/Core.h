#pragma once

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

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

#include <vulkan/vulkan.h>

#ifdef WINDOW_TYPE_GLFW
#include<GLFW\glfw3.h>
#endif // WINDOW_TYPE_GLFW

#ifdef WINDOW_TYPE_WINAPI
#include <Windows.h>
#endif // WINDOW_TYPE_WINAPI

#include "System/Platform/Platform.h"