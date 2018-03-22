#pragma once

#include <Shaft/Core.h>
#include <rttr/type>
#include <rttr/registration_friend>

namespace Shaft
{
	class World;

	class Actor
	{
	public:
		Actor(EngineEntity entity, World* world);
		~Actor();
		void SetName(const std::string& name);
		const std::string& GetName() const;
		void AddChild(Actor* child);
		const std::vector<Actor*>& GetChilren() const;
		void SetParent(Actor* parent);

		World* GetWorld();
		EngineEntity& GetEntity();
		
	protected:
		World* m_world;
		EngineEntity m_entity;
		Actor* m_parent;
		std::vector<Actor*> m_children;
		std::string m_name;

		RTTR_ENABLE()
		RTTR_REGISTRATION_FRIEND
	};
}