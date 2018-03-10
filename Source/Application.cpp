#include "Application.h"
#include "Engine/EngineFactory.h"
#include "Engine/System/Misc/EngineConfig.h"
#include "Engine/Engine.h"
#include "Engine/System/Window/WindowHandle.h"

using namespace Shaft;

Application::Application()
{
}

Application::~Application()
{
}

void Application::Initialize()
{
	EngineConfig engineConfig;
	engineConfig.buildTarget = Windows;
	engineConfig.rendererType = Vulkan;

	EngineFactory engineFactory;
	m_engine = engineFactory.CreateEngine(engineConfig);

	m_engine->Initialize();
	
}

void Shaft::Application::Run()
{
	while (!m_engine->GetWindow().CloseWindow())
	{
		m_engine->GetWindow().PollEvents();
	}
}
