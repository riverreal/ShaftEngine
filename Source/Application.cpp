#include <Shaft/Application.h>
#include "Engine/EngineFactory.h"
#include "Engine/Engine.h"
#include "Engine/System/Window/WindowHandle.h"
#include "Engine/Graphics/Renderer/Renderer.h"
#include "Engine/World.h"
#include <thread>

using namespace Shaft;

const float FIXED_TIMESTEP = 0.02f;

Application::Application()
	:m_materialManager(nullptr),
	m_textureManager(nullptr),
	m_meshManager(nullptr),
	m_fileSystem(nullptr)
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

	OnInitialize();

	EngineFactory engineFactory;
	m_engine = engineFactory.CreateEngine(m_engineConfig);
	m_engine->Initialize();

	m_world = &m_engine->GetWorld();
	m_materialManager = &m_engine->GetResourceManager().GetMaterialManager();
	m_meshManager = &m_engine->GetResourceManager().GetMeshManager();
	m_textureManager = &m_engine->GetResourceManager().GetTextureManager();
	m_fileSystem = &m_engine->GetResourceManager().GetFileSystem();

	m_engine->GetTimer().TimeStart();
}

void Shaft::Application::Run()
{
	FPSConfig& fpsConfig = m_engineConfig.renderConfig.fpsConfig;
	float acc = 0.0f;

	while (!m_engine->GetWindow().CloseWindow())
	{
		float dt = m_engine->GetTimer().GetDeltaTime();
		m_engine->GetTimer().Tick();
		m_engine->GetWindow().PollEvents();
		acc += dt;
		
		while (acc >= FIXED_TIMESTEP)
		{
			m_engine->GetWorld().FixedUpdate(FIXED_TIMESTEP);
			acc -= FIXED_TIMESTEP;
		}

		Frame();
		m_engine->GetWorld().Update(dt);

#if SHAFT_EDITOR_ENABLED
		m_engine->GetEditor().Draw();
#endif
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
