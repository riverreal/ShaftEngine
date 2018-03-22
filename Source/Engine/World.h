#pragma once

#include <Shaft/Core.h>
#include "Actor.h"

namespace Shaft
{
	class World
	{
	public:
		World();
		~World();

		const std::vector<std::unique_ptr<Actor>>& GetActors();

		template <typename T>
		T* CreateActor();
		
	private:
		std::vector<std::unique_ptr<Actor>> m_actors;
		EngineEntityManager m_entities;
	};

	template <typename T>
	T* World::CreateActor()
	{
		//Actor* actor = new T(m_entities.create());
		m_actors.push_back(std::make_unique<T>(m_entities.create(), this));
		return m_actors.back().get();
	}
}