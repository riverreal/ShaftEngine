#pragma once

#include "../../Core.h"
#include "WindowHandle.h"

namespace Shaft 
{
	struct WindowConfig;

	class GLFWWindowHandle : public WindowHandle
	{
	public:
		GLFWWindowHandle(const WindowConfig& config);
		~GLFWWindowHandle();
		virtual void Initialize() override;
		virtual bool CloseWindow() override;
		virtual void PollEvents() override;
		virtual void Destroy() override;

	private:
		void* glfwNativeWindowHandle();
		void SetBGFXWindow();
		
	private:
		const WindowConfig& m_config;
	};
}