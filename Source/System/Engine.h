#pragma once

#include "Core.h"

namespace Shaft {
	class BaseWindowHandle;

	class Engine
	{
	public:
		Engine();
		~Engine();
		
		void CreateWindow(std::unique_ptr<BaseWindowHandle> windowHandle);
		void Initialize();
		BaseWindowHandle& GetWindow();

	private:
		std::unique_ptr<BaseWindowHandle> m_window;
	};
}