#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class TransformSystem;
	class ScriptableSystem;

	class SystemsManager
	{
	public:
		SystemsManager(EngineEntityManager* eManager);
		~SystemsManager();

		void InitializeSystems();
		void UpdateSystems(float deltaTime);
		void DelayedUpdate(float deltaTime);
		void FixedUpdate(float deltaTime);
	private:
		eastl::unique_ptr<TransformSystem> m_transformSystem;
		eastl::unique_ptr<ScriptableSystem> m_scriptableSystem;
	};
}