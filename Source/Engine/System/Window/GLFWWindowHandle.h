#pragma once

#include "../../Core.h"
#include "WindowHandle.h"

namespace Shaft 
{
	class GLFWWindowHandle : public BaseWindowHandle
	{
	public:
		~GLFWWindowHandle();
		virtual void Initialize(std::string appName) override;
		virtual bool CloseWindow() override;
		virtual void PollEvents() override;
		virtual void Destroy() override;
	};
}