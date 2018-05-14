#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class TransformSystem;

	class SystemsManager
	{
	public:
		SystemsManager(EngineEntityManager* eManager);
		~SystemsManager();

		void InitializeSystems();
		void UpdateSystems(float deltaTime);

	private:
		eastl::unique_ptr<TransformSystem> m_transformSystem;
	};
}