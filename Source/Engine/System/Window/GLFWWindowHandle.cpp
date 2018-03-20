#include "GLFWWindowHandle.h"
#include <GLFW/glfw3native.h>
#include <bgfx/platform.h>
#include "../Misc/EngineConfig.h"
#include "../Input/Input.h"

Shaft::Input* Shaft::GLFWWindowHandle::sm_input;

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

void Shaft::GLFWWindowHandle::BindInput(Input* input)
{
	sm_input = input;

	//Set callbacks
	glfwSetMouseButtonCallback(m_windowHandle, MouseButtonCB);
	glfwSetCursorPosCallback(m_windowHandle, CursorPositionCB);
}

void * Shaft::GLFWWindowHandle::GlfwNativeWindowHandle()
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
	pd.nwh = GlfwNativeWindowHandle();
	pd.context = NULL;
	pd.backBuffer = NULL;
	pd.backBufferDS = NULL;
	bgfx::setPlatformData(pd);
}

void Shaft::GLFWWindowHandle::CursorPositionCB(GLFWwindow * window, double mouseX, double mouseY)
{
	sm_input->GetMouseState().mouseX = (int32)mouseX;
	sm_input->GetMouseState().mouseY = (int32)mouseY;
}

void Shaft::GLFWWindowHandle::MouseButtonCB(GLFWwindow * window, int32 button, int32 action, int32 mods)
{
	MouseState::MouseButton mButton = MouseState::Middle;
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		mButton = MouseState::Left;
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		mButton = MouseState::Right;
	}
	
	sm_input->GetMouseState().buttons[mButton] = action == GLFW_PRESS;
}
