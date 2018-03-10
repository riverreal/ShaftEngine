#include "Engine.h"
#include "System/Window/WindowHandle.h"

using namespace Shaft;

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::CreateWindow(std::unique_ptr<BaseWindowHandle> windowHandle)
{
	m_window = std::move(windowHandle);
}

void Shaft::Engine::Initialize()
{
	m_window->Initialize("Shaft Engine");
}

BaseWindowHandle& Engine::GetWindow()
{
	return *m_window.get();
}
