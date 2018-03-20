#include "GLFWWindowHandle.h"
#include "../Misc/EngineConfig.h"
#include <GLFW/glfw3native.h>
#include <bgfx/platform.h>

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
	m_windowHandle = glfwCreateWindow(m_config.width, m_config.height, 
		m_config.appInfo.appName.c_str(), nullptr, nullptr);

	//Bind created window to bgfx
	SetBGFXWindow();
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

void * Shaft::GLFWWindowHandle::glfwNativeWindowHandle()
{
#	if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	return (void*)(uintptr_t)glfwGetX11Window(m_windowHandle);
#	elif BX_PLATFORM_OSX
	return glfwGetCocoaWindow(m_windowHandle);
#	elif BX_PLATFORM_WINDOWS
	return glfwGetWin32Window(m_windowHandle);
#	endif
}

void Shaft::GLFWWindowHandle::SetBGFXWindow()
{
	bgfx::PlatformData pd;
#	if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	pd.ndt = glfwGetX11Display();
#	elif BX_PLATFORM_OSX
	pd.ndt = NULL;
#	elif BX_PLATFORM_WINDOWS
	pd.ndt = NULL;
#	endif // BX_PLATFORM_WINDOWS
	pd.nwh = glfwNativeWindowHandle();
	pd.context = NULL;
	pd.backBuffer = NULL;
	pd.backBufferDS = NULL;
	bgfx::setPlatformData(pd);
}
