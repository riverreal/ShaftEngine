#include "Engine.h"
#include "System/Window/WindowHandle.h"
#include "Graphics/Renderer/Renderer.h"
#include "System/Misc/EngineConfig.h"

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

void Shaft::Engine::Initialize()
{
	m_window->Initialize();
	m_renderer->Initialize(GetWindow());
}

WindowHandle& Engine::GetWindow()
{
	return *m_window.get();
}

Renderer & Shaft::Engine::GetRenderer()
{
	return *m_renderer.get();
}
