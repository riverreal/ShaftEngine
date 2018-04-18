#pragma once

#include <Shaft/Core.h>
#include "Engine/System/Misc/EngineConfig.h"
#include "../Engine/System/Misc/STween.h"

namespace Shaft {
	class Engine;
	class Actor;

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
		void Animate();

	protected:
		std::unique_ptr<Engine> m_engine;

	private:
		EngineConfig m_engineConfig;
		STween::STween<float> m_tween;
		Shaft::Actor* m_cube;
	};
}