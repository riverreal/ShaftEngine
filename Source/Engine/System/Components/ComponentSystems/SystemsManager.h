#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class TransformSystem;
	class ScriptableSystem;
	class CameraSystem;
	class BillboardSystem;
	struct EngineConfig;
	class World;

	class SystemsManager
	{
	public:
		SystemsManager(EngineEntityManager* eManager, World* world);
		~SystemsManager();

		void InitializeSystems(EngineConfig& config);
		void UpdateSystems(float deltaTime);
		void DelayedUpdate(float deltaTime);
		void FixedUpdate(float deltaTime);
	private:
		eastl::unique_ptr<TransformSystem> m_transformSystem;
		eastl::unique_ptr<ScriptableSystem> m_scriptableSystem;
		eastl::unique_ptr<CameraSystem> m_cameraSystem;
		eastl::unique_ptr<BillboardSystem> m_billboardSystem;
	};
}