#include "GLFWWindowHandle.h"

Shaft::GLFWWindowHandle::~GLFWWindowHandle()
{
	Destroy();
}

void Shaft::GLFWWindowHandle::Initialize(std::string appName)
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	m_windowHandle = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, appName.c_str(), nullptr, nullptr);
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
	std::cout << "Window destroyed" << std::endl;
}
