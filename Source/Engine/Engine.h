#pragma once

#include "Core.h"

namespace Shaft {
	class WindowHandle;
	class Renderer;
	struct EngineConfig;

	class Engine
	{
	public:
		Engine(const EngineConfig& config);
		~Engine();
		//Has to be called after window and renderer are set
		void Initialize();
		void SetWindow(std::unique_ptr<WindowHandle> windowHandle);
		void SetRenderer(std::unique_ptr<Renderer> renderer);
		
		WindowHandle& GetWindow();
		Renderer& GetRenderer();

	private:
		std::unique_ptr<WindowHandle> m_window;
		std::unique_ptr<Renderer> m_renderer;
		const EngineConfig& m_engineConfig;
	};
}