#pragma once

#include "Core.h"

namespace Shaft {
	class BaseWindowHandle;

	class Engine
	{
	public:
		Engine();
		~Engine();

	private:
		std::unique_ptr<BaseWindowHandle> m_window;
	};
}