#pragma once

#include "../Core.h"

namespace Shaft
{
	class BaseWindowHandle
	{
	public:
		virtual ~BaseWindowHandle() {};
		virtual void Initialize(std::string appName) = 0;
		virtual bool CloseWindow() = 0;
		virtual void PollEvents() = 0;
		virtual void Destroy() = 0;

	protected:
#ifdef WINDOW_TYPE_GLFW 1
		GLFWwindow* m_windowHandle;
#elif WINDOW_TYPE_WINAPI
		HWND m_window;
#endif

	};
}
