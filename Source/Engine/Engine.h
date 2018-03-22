#pragma once

#include <Shaft/Core.h>
#include "System/Input/Input.h"

#if SHAFT_EDITOR_ENABLED
#include "Editor/ShaftEditor.h"
#endif

namespace Shaft {
	class WindowHandle;
	class Renderer;
	class World;
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
		
#if SHAFT_EDITOR_ENABLED
		void SetEditor(std::unique_ptr<ShaftEditor> editor);
		ShaftEditor& GetEditor();
#endif

		WindowHandle& GetWindow();
		Renderer& GetRenderer();
		Input& GetInput();
		World& GetWorld();

	private:
		std::unique_ptr<WindowHandle> m_window;
		std::unique_ptr<Renderer> m_renderer;
		std::unique_ptr<World> m_world;
		Input m_input;
		const EngineConfig& m_engineConfig;

#if SHAFT_EDITOR_ENABLED
		std::unique_ptr<ShaftEditor> m_editor;
#endif
	};
}