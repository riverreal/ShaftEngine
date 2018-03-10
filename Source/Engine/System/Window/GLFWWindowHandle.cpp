#include "GLFWWindowHandle.h"
#include "../Misc/EngineConfig.h"

Shaft::GLFWWindowHandle::GLFWWindowHandle(const WindowConfig& config)
	:m_config(config)
{
}

Shaft::GLFWWindowHandle::~GLFWWindowHandle()
{
	Destroy();
}

void Shaft::GLFWWindowHandle::Initialize()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, m_config.isResizeable);
	m_windowHandle = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, m_config.appInfo.appName.c_str(), nullptr, nullptr);
}

bool Shaft::GLFWWindowHandle::CloseWindow()
{
	return glfwWindowShouldClose(m_windowHandle);
}

void Shaft::GLFWWindowHandle::PollEvents()
{
	glfwPollEvents();
}

void Shaft::GLFWWindowHandle::Destroy()
{
	glfwDestroyWindow(m_windowHandle);
	glfwTerminate();
}
