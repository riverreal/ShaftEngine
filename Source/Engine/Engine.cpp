#include "Engine.h"
#include "System/Window/WindowHandle.h"
#include "Graphics/Renderer/Renderer.h"
#include "System/Misc/EngineConfig.h"
#include "System/ResourceManager.h"
#include "World.h"

using namespace Shaft;

Engine::Engine(const EngineConfig& config)
	:m_engineConfig(config)
{
}

Engine::~Engine()
{
}

void Engine::SetWindow(std::unique_ptr<WindowHandle> windowHandle)
{
	m_window = std::move(windowHandle);
}

void Shaft::Engine::SetRenderer(std::unique_ptr<Renderer> renderer)
{
	m_renderer = std::move(renderer);
}

#if SHAFT_EDITOR_ENABLED
void Shaft::Engine::SetEditor(std::unique_ptr<ShaftEditor> editor)
{
	m_editor = std::move(editor);
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

	m_world = std::make_unique<World>();

	m_resourceManager = std::make_unique<ResourceManager>();
	m_resourceManager->Initialize();

	m_renderer->Initialize(m_world.get(), m_resourceManager.get());

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

World & Shaft::Engine::GetWorld()
{
	return *m_world.get();
}

ResourceManager & Shaft::Engine::GetResourceManager()
{
	// TODO: insert return statement here
	return *m_resourceManager.get();
}
