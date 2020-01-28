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
	glfwSetKeyCallback(m_windowHandle,KeyCB);
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

void Shaft::GLFWWindowHandle::KeyCB(GLFWwindow* window, int32 key, int32_t scancode, int32 action, int32 mods)
{
	BX_UNUSED(scancode);
	
	if (key == GLFW_KEY_UNKNOWN)return;

	KeyState::Key _key = (KeyState::Key)GlfwKeyToShaftKey(key);

	sm_input->GetKeyState().keys[_key] = action == GLFW_PRESS || action == GLFW_REPEAT;
}


int32 Shaft::GLFWWindowHandle::GlfwKeyToShaftKey(int32 key)
{

	switch (key)
	{
		case GLFW_KEY_ESCAPE:
			return KeyState::Esc;
		case GLFW_KEY_ENTER:
			return KeyState::Return;
		case GLFW_KEY_TAB:
			return KeyState::Tab;
		case GLFW_KEY_BACKSPACE:
			return KeyState::Backspace;
		case GLFW_KEY_SPACE:
			return KeyState::Space;
		case GLFW_KEY_UP:
			return KeyState::Up;
		case GLFW_KEY_DOWN:
			return KeyState::Down;
		case GLFW_KEY_LEFT:
			return KeyState::Left;
		case GLFW_KEY_RIGHT:
			return KeyState::Right;
		case GLFW_KEY_PAGE_UP:
			return KeyState::PageUp;
		case GLFW_KEY_PAGE_DOWN:
			return KeyState::PageDown;
		case GLFW_KEY_HOME:
			return KeyState::Home;
		case GLFW_KEY_END:
			return KeyState::End;
		case GLFW_KEY_PRINT_SCREEN:
			return KeyState::Print;
		case GLFW_KEY_KP_ADD:
			return KeyState::Plus;
		case GLFW_KEY_EQUAL:
			return KeyState::Plus;
		case GLFW_KEY_MINUS:
			return KeyState::Minus;
		case GLFW_KEY_KP_SUBTRACT:
			return KeyState::Minus;
		case GLFW_KEY_COMMA:
			return KeyState::Comma;
		case GLFW_KEY_PERIOD:
			return KeyState::Period;
		case GLFW_KEY_SLASH:
			return KeyState::Slash;
		case GLFW_KEY_F1:
			return KeyState::F1;
		case GLFW_KEY_F2:
			return KeyState::F2;
		case GLFW_KEY_F3:
			return KeyState::F3;
		case GLFW_KEY_F4:
			return KeyState::F4;
		case GLFW_KEY_F5:
			return KeyState::F5;
		case GLFW_KEY_F6:
			return KeyState::F6;
		case GLFW_KEY_F7:
			return KeyState::F7;
		case GLFW_KEY_F8:
			return KeyState::F8;
		case GLFW_KEY_F9:
			return KeyState::F9;
		case GLFW_KEY_F10:
			return KeyState::F10;
		case GLFW_KEY_F11:
			return KeyState::F11;
		case GLFW_KEY_F12:
			return KeyState::F12;
		case GLFW_KEY_KP_0:
			return KeyState::NumPad0;
		case GLFW_KEY_KP_1:
			return KeyState::NumPad2;
		case GLFW_KEY_KP_2:
			return KeyState::NumPad2;
		case GLFW_KEY_KP_3:
			return KeyState::NumPad3;
		case GLFW_KEY_KP_4:
			return KeyState::NumPad4;
		case GLFW_KEY_KP_5:
			return KeyState::NumPad5;
		case GLFW_KEY_KP_6:
			return KeyState::NumPad6;
		case GLFW_KEY_KP_7:
			return KeyState::NumPad7;
		case GLFW_KEY_KP_8:
			return KeyState::NumPad8;
		case GLFW_KEY_KP_9:
			return KeyState::NumPad9;
		case GLFW_KEY_0:
			return KeyState::Key0;
		case GLFW_KEY_1:
			return KeyState::Key1;
		case GLFW_KEY_2:
			return KeyState::Key2;
		case GLFW_KEY_3:
			return KeyState::Key3;
		case GLFW_KEY_4:
			return KeyState::Key4;
		case GLFW_KEY_5:
			return KeyState::Key5;
		case GLFW_KEY_6:
			return KeyState::Key6;
		case GLFW_KEY_7:
			return KeyState::Key7;
		case GLFW_KEY_8:
			return KeyState::Key8;
		case GLFW_KEY_9:
			return KeyState::Key9;
		case GLFW_KEY_A:
			return KeyState::A;
		case GLFW_KEY_B:
			return KeyState::B;
		case GLFW_KEY_C:
			return KeyState::C;
		case GLFW_KEY_D:
			return KeyState::D;
		case GLFW_KEY_E:
			return KeyState::E;
		case GLFW_KEY_F:
			return KeyState::F;
		case GLFW_KEY_G:
			return KeyState::G;
		case GLFW_KEY_H:
			return KeyState::H;
		case GLFW_KEY_I:
			return KeyState::I;
		case GLFW_KEY_J:
			return KeyState::J;
		case GLFW_KEY_K:
			return KeyState::K;
		case GLFW_KEY_L:
			return KeyState::L;
		case GLFW_KEY_N:
			return KeyState::N;
		case GLFW_KEY_M:
			return KeyState::M;
		case GLFW_KEY_O:
			return KeyState::O;
		case GLFW_KEY_P:
			return KeyState::P;
		case GLFW_KEY_Q:
			return KeyState::Q;
		case GLFW_KEY_R:
			return KeyState::R;
		case GLFW_KEY_S:
			return KeyState::S;
		case GLFW_KEY_T:
			return KeyState::T;
		case GLFW_KEY_U:
			return KeyState::U;
		case GLFW_KEY_V:
			return KeyState::V;
		case GLFW_KEY_W:
			return KeyState::W;
		case GLFW_KEY_X:
			return KeyState::X;
		case GLFW_KEY_Y:
			return KeyState::Y;
		case GLFW_KEY_Z:
			return KeyState::Z;
	default:
		return KeyState::Max;
		break;
	}
}