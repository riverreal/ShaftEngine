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
		virtual void BindInput(Input* input) override;

	private:
		void* GlfwNativeWindowHandle();
		void SetBGFXWindow();

		static void CursorPositionCB(GLFWwindow* window, double mouseX, double mouseY);
		static void MouseButtonCB(GLFWwindow* window, int32 button, int32 action, int32 mods);

		static void KeyCB(GLFWwindow* window, int32 key, int32_t scancode, int32 action, int32 mods);
		static int32 GlfwKeyToShaftKey(int32 key);
		
	private:
		static Input* sm_input;
		const WindowConfig& m_config;
	};
	
}