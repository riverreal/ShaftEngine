#pragma once

#include <Shaft/Core.h>

namespace Shaft {
	struct EngineConfig;
	class Engine;
	enum TargetOS;

	class EngineFactory
	{
	public:
		EngineFactory();
		~EngineFactory();

		eastl::unique_ptr<Engine> CreateEngine(EngineConfig& config);
	private:
		void ResolveBuildTarget(const EngineConfig& config);

	private:
		TargetOS m_devTarget;
		TargetOS m_buildTarget;
	};
}