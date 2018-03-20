#include "EngineFactory.h"

#include "Engine.h"
#include "System/Misc/EngineConfig.h"
#include "System/Platform/Platform.h"
#include "System/Window/WindowIncludes.h"
#include "Graphics/Renderer/Renderer.h"

using namespace Shaft;

EngineFactory::EngineFactory()
{
#if PLATFORM_WINDOWS
	m_devTarget = TargetOS::Windows;
#elif
	m_devTarget = TargetOS::MacOS;
#elif
	m_devTarget = TargetOS::Linux;
#endif
}

EngineFactory::~EngineFactory()
{
}

std::unique_ptr<Engine> EngineFactory::CreateEngine(const EngineConfig & config)
{
	ResolveBuildTarget(config);

	std::unique_ptr<Engine> engine(new Engine(config));
	
	//--------Renderer---------------------------
	std::unique_ptr<Renderer> renderer(new Renderer(config.renderConfig));
	engine->SetRenderer(std::move(renderer));

	//--------Window-----------------------------
	std::unique_ptr<WindowHandle> windowHandle(new GLFWWindowHandle(config.windowConfig));
	engine->SetWindow(std::move(windowHandle));

	return engine;
}

void EngineFactory::ResolveBuildTarget(const EngineConfig& config)
{
	//Only allow compatible build targets
	switch (m_devTarget)
	{
	case TargetOS::Windows:
		if (config.buildTarget == Android || config.buildTarget == Windows)
		{
			m_buildTarget = config.buildTarget;
		}
		else
		{
			m_buildTarget = Windows;
		}

		break;
	case TargetOS::MacOS:
		if (config.buildTarget == MacOS || config.buildTarget == Android || config.buildTarget == IOS)
		{
			m_buildTarget = config.buildTarget;
		}
		else
		{
			m_buildTarget = MacOS;
		}
		break;

	case TargetOS::Linux:
		if (config.buildTarget == Linux || config.buildTarget == Android)
		{
			m_buildTarget = config.buildTarget;
		}
		else
		{
			m_buildTarget = Linux;
		}
		break;
	default:
		m_buildTarget = Windows;
		break;
	}
}