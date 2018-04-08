#include <Shaft/DebugApp.h>
#include "Engine/EngineFactory.h"
#include "Engine/Engine.h"
#include "Engine/System/Window/WindowHandle.h"
#include "Engine/Graphics/Renderer/Renderer.h"
#include "Engine/World.h"

using namespace Shaft;

DebugApp::DebugApp()
{
}

DebugApp::~DebugApp()
{
}

void DebugApp::Initialize()
{
	
	m_engineConfig.buildTarget = Windows;
	m_engineConfig.renderConfig.rendererType = Direct3D11;
	m_engineConfig.windowConfig.isResizeable = false;
	m_engineConfig.appInfo.appName = "Shaft Engine Test";
	m_engineConfig.appInfo.appVersion = Version(0, 0, 1);
	m_engineConfig.renderConfig.appInfo = m_engineConfig.windowConfig.appInfo = m_engineConfig.appInfo;
	m_engineConfig.renderConfig.isValidationEnabled = true;
	m_engineConfig.renderConfig.engineName = "Shaft Engine";
	m_engineConfig.engineVersion = m_engineConfig.renderConfig.engineVersion = Version(0, 0, 1);

	EngineFactory engineFactory;

	m_engine = engineFactory.CreateEngine(m_engineConfig);
	m_engine->Initialize();

	//AppInit();
}

void Shaft::DebugApp::Run()
{
	while (!m_engine->GetWindow().CloseWindow())
	{
		m_engine->GetWindow().PollEvents();

		//TODO: delta time
		m_engine->GetWorld().Update(0);

		//AppRun();

#if SHAFT_EDITOR_ENABLED
		m_engine->GetEditor().Draw();
#endif

		m_engine->GetRenderer().Draw();
	}
}
