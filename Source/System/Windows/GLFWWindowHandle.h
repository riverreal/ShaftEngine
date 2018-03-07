#pragma once

#include "../Core.h"
#include <GLFW/glfw3.h>
#include "../BasePlatform/BaseWindowHandle.h"

namespace Shaft 
{
	class GLFWWindowHandle : public BaseWindowHandle
	{
	public:
		virtual void Initialize(std::string appName) override;
		virtual bool CloseWindow() override;
	};
}