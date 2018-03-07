#include "GLFWWindowHandle.h"

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
