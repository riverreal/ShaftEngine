#pragma once

#include <Shaft/Core.h>
#include "System/Input/Input.h"
#include "System/Timer.h"
#include "System/Misc/EngineConfig.h"

#if SHAFT_EDITOR_ENABLED
#include "Editor/ShaftEditor.h"
#endif

namespace Shaft {
	class WindowHandle;
	class Renderer;
	class World;
	class ResourceManager;

	class Engine
	{
	public:
		Engine(EngineConfig& config);
		~Engine();
		//Has to be called after window and renderer are set
		void Initialize();
		void SetWindow(eastl::unique_ptr<WindowHandle> windowHandle);
		void SetRenderer(eastl::unique_ptr<Renderer> renderer);
		
#if SHAFT_EDITOR_ENABLED
		void SetEditor(eastl::unique_ptr<ShaftEditor> editor);
		ShaftEditor& GetEditor();
#endif

		WindowHandle& GetWindow();
		Renderer& GetRenderer();
		Input& GetInput();
		Timer& GetTimer();
		World& GetWorld();
		ResourceManager& GetResourceManager();

	private:
		eastl::unique_ptr<WindowHandle> m_window;
		eastl::unique_ptr<Renderer> m_renderer;
		eastl::unique_ptr<World> m_world;
		eastl::unique_ptr<ResourceManager> m_resourceManager;
		Input m_input;
		Timer m_timer;
		EngineConfig& m_engineConfig;

#if SHAFT_EDITOR_ENABLED
		eastl::unique_ptr<ShaftEditor> m_editor;
#endif
	};
}