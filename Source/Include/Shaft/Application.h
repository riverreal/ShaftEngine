#pragma once

#include <Shaft/Core.h>
#include "../../Engine/System/Misc/EngineConfig.h"

namespace Shaft {
	class Engine;

	class Application
	{
	public:
		Application();
		~Application();
		void Initialize();
		void Run();

	protected:
		virtual void AppInit() = 0;
		virtual void AppRun() = 0;

	protected:
		eastl::unique_ptr<Engine> m_engine;

	private:
		EngineConfig m_engineConfig;
	};
}