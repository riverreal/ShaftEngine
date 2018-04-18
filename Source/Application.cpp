#include <Shaft/Application.h>
#include "Engine/EngineFactory.h"
#include "Engine/Engine.h"
#include "Engine/System/Window/WindowHandle.h"
#include "Engine/Graphics/Renderer/Renderer.h"
#include "Engine/World.h"
#include <thread>

using namespace Shaft;

Application::Application()
{
}

Application::~Application()
{
}

void Application::Initialize()
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

	AppInit();

	m_engine->GetTimer().TimeStart();
}

void Shaft::Application::Run()
{
	FPSConfig& fpsConfig = m_engineConfig.renderConfig.fpsConfig;

	while (!m_engine->GetWindow().CloseWindow())
	{
		float dt = m_engine->GetTimer().GetDeltaTime();
		m_engine->GetTimer().Tick();
		m_engine->GetWindow().PollEvents();

		m_engine->GetWorld().Update(dt);

		AppRun();

#if SHAFT_EDITOR_ENABLED
		m_engine->GetEditor().Draw();
#endif

		//Draw will automatically set correct frame time if vsync is on
		m_engine->GetRenderer().Draw();

		if (!fpsConfig.vsync && fpsConfig.capFPS)
		{
			auto sleepMS = static_cast<int32>(1000.0f / (float)fpsConfig.fps - dt * 1000.0f);
			if (sleepMS > 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(sleepMS));
			}
		}
	}
}
