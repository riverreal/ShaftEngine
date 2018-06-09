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

		template <class C>
		C* AddScript();

		template <class C>
		void RemoveScript();

		template <class C>
		C* GetScript();

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
		ScriptableComponent* m_scriptableComp;

	private:
		bool m_scripted;
	};

	template<typename C, typename ...Args>
	inline C* Actor::AddComponent(Args && ... args)
	{
		return m_entity.assign<C>(eastl::forward<Args>(args)...);
	}

	template<class C>
	inline C* Actor::AddScript()
	{
		if (!m_scripted)
		{
			m_scriptableComp = m_entity.assign<ScriptableComponent>();
			m_scripted = true;
		}

		C* script = new C;
		m_scriptableComp->scripts[&(typeid(C))] = eastl::unique_ptr<C>(script);
		script->Initialize(m_world, this, m_transform);
		script->OnAttach();
		return script;
	}

	template<class C>
	inline void Actor::RemoveScript()
	{
		if (!m_scripted)
		{
			return;
		}

		auto script = m_scriptableComp->scripts.find(&(typeid(C)));
		if (script != nullptr)
		{
			script->second->Destroy();
			m_scriptableComp->scripts.erase(&(typeid(C)));
		}
	}

	template<class C>
	inline C * Actor::GetScript()
	{
		if (!m_scripted)
		{
			return nullptr;
		}
		
		auto script = m_scriptableComp->scripts.find(&(typeid(C)));
		if (script == m_scriptableComp->scripts.end())
		{
			return nullptr;
		}
		else
		{
			return static_cast<C*>(script->second.get());
		}
	}
}