#pragma once

#include "../../Core.h"

namespace Shaft
{
	class WindowHandle
	{
	public:
		virtual ~WindowHandle() {};
		virtual void Initialize() = 0;
		virtual bool CloseWindow() = 0;
		virtual void PollEvents() = 0;
		virtual void Destroy() = 0;

#ifdef WINDOW_TYPE_GLFW 1
		GLFWwindow* GetWindow() { return m_windowHandle; }
#elif WINDOW_TYPE_WINAPI
		HWND GetWindow() { return m_windowHandle; }
#endif

	protected:
#ifdef WINDOW_TYPE_GLFW 1
		GLFWwindow* m_windowHandle;
#elif WINDOW_TYPE_WINAPI
		HWND m_windowHandle;
#endif

	};
}
