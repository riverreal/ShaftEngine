#pragma once

#include <Shaft/Core.h>
#include "Actor.h"

namespace Shaft
{
	struct IDActor {
		uint64 id;
		std::unique_ptr<Actor> actor;
	};

	class World
	{
	public:
		World();
		~World();

		const std::vector<IDActor>& GetActors();

		template <typename T>
		T* CreateActor();
		void RemoveActor(Actor* actor);

		void RemoveAllActors();

	private:
		std::vector<IDActor> m_actors;
		EngineEntityManager m_entities;
	};

	template <typename T>
	T* World::CreateActor()
	{
		IDActor idActor;
		idActor.actor = std::make_unique<T>(m_entities.create(), this);
		idActor.id = idActor.actor.get()->GetEntity().id().id();
		m_actors.push_back(std::move(idActor));
		//m_actors.emplace_back(std::move(idActor));

		return m_actors.back().actor.get();
	}
}