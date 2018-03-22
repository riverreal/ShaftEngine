#pragma once

#include "../../Core.h"

namespace Shaft
{
	class Input;

	class WindowHandle
	{
	public:
		virtual ~WindowHandle() {};
		virtual void Initialize() = 0;
		virtual bool CloseWindow() = 0;
		virtual void PollEvents() = 0;
		virtual void Destroy() = 0;
		virtual void BindInput(Input* input) = 0;

#if WINDOW_TYPE_GLFW
		GLFWwindow* GetWindow() { return m_windowHandle; }
#elif WINDOW_TYPE_WINAPI
		HWND GetWindow() { return m_windowHandle; }
#endif

	protected:
#if WINDOW_TYPE_GLFW
		GLFWwindow* m_windowHandle;
#elif WINDOW_TYPE_WINAPI
		HWND m_windowHandle;
#endif

	};
}
