#pragma once

#include <Shaft/Core.h>
#include "Engine/System/Misc/EngineConfig.h"

namespace Shaft {
	class Engine;

	class DebugApp
	{
	public:
		DebugApp();
		~DebugApp();
		void Initialize();
		void Run();

	protected:
		//virtual void AppInit() = 0;
		//virtual void AppRun() = 0;

	protected:
		std::unique_ptr<Engine> m_engine;

	private:
		EngineConfig m_engineConfig;
	};
}