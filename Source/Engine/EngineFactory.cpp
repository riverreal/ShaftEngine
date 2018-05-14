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

eastl::unique_ptr<Engine> EngineFactory::CreateEngine(EngineConfig & config)
{
	ResolveBuildTarget(config);

	eastl::unique_ptr<Engine> engine = eastl::make_unique<Engine>(config);
	
	//--------Renderer---------------------------
	eastl::unique_ptr<Renderer> renderer = eastl::make_unique<Renderer>(config.renderConfig);
	engine->SetRenderer(eastl::move(renderer));

	//--------Window-----------------------------
	eastl::unique_ptr<WindowHandle> windowHandle = eastl::make_unique<GLFWWindowHandle>(config.windowConfig);
	engine->SetWindow(eastl::move(windowHandle));

#if SHAFT_EDITOR_ENABLED
	eastl::unique_ptr<ShaftEditor> editor = eastl::make_unique<ShaftEditor>(config);
	engine->SetEditor(eastl::move(editor));
#endif

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
