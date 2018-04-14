#pragma once

#include <Shaft/Core.h>
#include <Shaft/Reflection.h>

namespace Shaft
{
	class World;

	class Actor
	{
		REFLECTABLE(Actor)
	public:
		Actor(EngineEntity entity, World* world);
		~Actor();
		void SetName(const std::string& name);
		const std::string& GetName() const;
		void AddChild(Actor* child);
		//For deparent purposes
		void RemoveChild(Actor* child);
		const std::vector<Actor*>& GetChilren() const;
		Actor* GetParent();
		void SetParent(Actor* parent);
		void Destroy();
		World* GetWorld();
		EngineEntity& GetEntity();
		Actor* GetRoot();
		bool GetActive();
		void SetActive(bool active);
		Transform* GetTransform();

	private:
		void SetParentPtr(Actor* parent);
		Actor* GetRootRec(Actor* target);

	protected:
		World* m_world;
		EngineEntity m_entity;
		Actor* m_parent;
		std::vector<Actor*> m_children;
		std::string m_name;
		bool m_active;
		Transform* m_transform;
	};
}