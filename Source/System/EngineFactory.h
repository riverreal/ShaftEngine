#pragma once

#include "Core.h"

namespace Shaft {
	struct EngineConfig;
	class Engine;
	enum TargetOS;

	class EngineFactory
	{
	public:
		EngineFactory();
		~EngineFactory();

		Engine* CreateEngine(const EngineConfig& config);
	private:
		void ResolveBuildTarget(const EngineConfig& config);

	private:
		TargetOS m_devTarget;
		TargetOS m_buildTarget;
	};
}