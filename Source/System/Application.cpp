#include "Application.h"
#include "EngineFactory.h"
#include "Misc\EngineConfig.h"
#include "Engine.h"
#include "BasePlatform\BaseWindowHandle.h"

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
