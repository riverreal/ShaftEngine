#include "Application.h"
#include "Engine/EngineFactory.h"
#include "Engine/System/Misc/EngineConfig.h"
#include "Engine/Engine.h"
#include "Engine/System/Window/WindowHandle.h"
#include "Engine/Graphics/Renderer/Renderer.h"

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
	engineConfig.renderConfig.rendererType = Direct3D11;
	
	engineConfig.windowConfig.isResizeable = false;

	engineConfig.appInfo.appName = "Shaft Engine Test";
	engineConfig.appInfo.appVersion = Version(0, 0, 1);
	engineConfig.renderConfig.appInfo = engineConfig.windowConfig.appInfo = engineConfig.appInfo;
	engineConfig.renderConfig.isValidationEnabled = true;
	
	engineConfig.renderConfig.engineName = "Shaft Engine";
	engineConfig.engineVersion = engineConfig.renderConfig.engineVersion = Version(0, 0, 1);

	EngineFactory engineFactory;
	m_engine = engineFactory.CreateEngine(engineConfig);

	m_engine->Initialize();
}

void Shaft::Application::Run()
{
	while (!m_engine->GetWindow().CloseWindow())
	{
		m_engine->GetWindow().PollEvents();
		m_engine->GetRenderer().Draw();
	}
}
