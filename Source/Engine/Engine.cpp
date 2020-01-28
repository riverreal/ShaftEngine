#include "Engine.h"
#include "System/Window/WindowHandle.h"
#include "Graphics/Renderer/Renderer.h"
#include "System/Misc/EngineConfig.h"
#include "System/ResourceManager.h"
#include "World.h"

using namespace Shaft;

Engine::Engine(EngineConfig& config)
	:m_engineConfig(config)
{
}

Engine::~Engine()
{
	m_resourceManager.reset();
}

void Engine::SetWindow(eastl::unique_ptr<WindowHandle> windowHandle)
{
	m_window = eastl::move(windowHandle);
}

void Shaft::Engine::SetRenderer(eastl::unique_ptr<Renderer> renderer)
{
	m_renderer = eastl::move(renderer);
}

#if SHAFT_EDITOR_ENABLED
void Shaft::Engine::SetEditor(eastl::unique_ptr<ShaftEditor> editor)
{
	m_editor = eastl::move(editor);
}
ShaftEditor& Shaft::Engine::GetEditor()
{
	return *m_editor.get();
}
#endif
void Shaft::Engine::Initialize()
{
	m_window->Initialize();
	m_window->BindInput(&m_input);

	m_world = eastl::make_unique<World>(m_engineConfig);

	m_resourceManager = eastl::make_unique<ResourceManager>();
	m_renderer->Initialize(m_world.get(), m_resourceManager.get());
	m_resourceManager->Initialize();
	m_world->Initialize();

#if SHAFT_EDITOR_ENABLED
	m_editor->Init();
	m_editor->BindInput(&m_input);
#endif
}

WindowHandle& Engine::GetWindow()
{
	return *m_window.get();
}

Renderer& Shaft::Engine::GetRenderer()
{
	return *m_renderer.get();
}

Input& Shaft::Engine::GetInput()
{
	return m_input;
}

Timer & Shaft::Engine::GetTimer()
{
	return m_timer;
}

World & Shaft::Engine::GetWorld()
{
	return *m_world.get();
}

ResourceManager & Shaft::Engine::GetResourceManager()
{
	return *m_resourceManager.get();
}
