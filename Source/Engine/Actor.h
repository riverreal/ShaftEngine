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
		void SetName(const eastl::string& name);
		const eastl::string& GetName() const;
		void AddChild(Actor* child);
		const eastl::vector<Actor*>& GetChilren() const;
		Actor* GetParent();
		void SetParent(Actor* parent);
		void Destroy();
		World* GetWorld();
		EngineEntity& GetEntity();
		Actor* GetRoot();
		bool GetActive();
		void SetActive(bool active);
		Transform* GetTransform();

		template <typename C, typename ... Args>
		C* AddComponent(Args && ... args);

	private:
		//For deparent purposes
		void RemoveChild(Actor* child);
		void SetParentPtr(Actor* parent);
		Actor* GetRootRec(Actor* target);

	protected:
		World* m_world;
		EngineEntity m_entity;
		Actor* m_parent;
		eastl::vector<Actor*> m_children;
		eastl::string m_name;
		bool m_active;
		Transform* m_transform;
	};

	template<typename C, typename ...Args>
	inline C * Actor::AddComponent(Args && ... args)
	{
		return m_entity.assign<C>(eastl::forward<Args>(args)...);
	}
}