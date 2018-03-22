#pragma once

#include <Shaft/Core.h>
#include "Engine/System/Misc/EngineConfig.h"

namespace Shaft {
	class Engine;

	class Application
	{
	public:
		Application();
		~Application();
		void Initialize();
		void Run();

	private:
		std::unique_ptr<Engine> m_engine;
		EngineConfig m_engineConfig;
	};
}