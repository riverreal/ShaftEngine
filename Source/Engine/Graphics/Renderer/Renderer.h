#pragma once

#include "../../Core.h"

namespace Shaft {
	class WindowHandle;

	class Renderer
	{
	public:
		~Renderer() {};
		virtual void Initialize(WindowHandle& windowHandle) = 0;
		virtual void Draw() = 0;
		virtual void Destroy() = 0;
	};
}