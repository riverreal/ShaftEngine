#pragma once

#include <Shaft/Core.h>
#include "Actor.h"

namespace Shaft
{
	class SystemsManager;
	struct EngineConfig;

	struct IDActor {
		uint32 id;
		eastl::unique_ptr<Actor> actor;
	};

	class World
	{
	public:
		World(EngineConfig& conf);
		~World();

		void Initialize();
		void Update(float deltaTime);
		void FixedUpdate(float deltaTime);

		const eastl::vector<IDActor>& GetActors();
		Actor* CreateActor();

		template <typename T>
		T* CreateActor();
		void RemoveActor(Actor* actor);

		void RemoveAllActors();

		void SetMainCamera(Actor* camera);
		Actor* GetMainCamera();

	private:
		Actor* m_mainCamera;
		eastl::vector<IDActor> m_actors;
		EngineEntityManager m_entities;
		eastl::unique_ptr<SystemsManager> m_systemsManager;
		EngineConfig& m_engineConfig;
	};

	template <typename T>
	T* World::CreateActor()
	{
		IDActor idActor;
		idActor.actor = eastl::make_unique<T>(m_entities.create(), this);
		idActor.id = static_cast<uint32>(idActor.actor.get()->GetEntity().id().id());
		m_actors.push_back(eastl::move(idActor));

		return m_actors.back().actor.get();
	}
}