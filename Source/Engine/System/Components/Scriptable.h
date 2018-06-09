#ifndef _SCRIPTABLE_H_
#define _SCRIPTABLE_H_
#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class World;
	class Actor;
	struct Transform;

	enum ScriptState
	{
		Start,
		LateStart,
		Update
	};

	class Scriptable
	{
		friend class ScriptableSystem;
	public:
		Scriptable()
			:m_world(nullptr), m_actor(nullptr), m_transform(nullptr), m_state(ScriptState::Start)
		{}

		virtual ~Scriptable() 
		{
			Destroy();
		}

		void Initialize(World* world, Actor* actor, Transform* transform)
		{
			m_world = world;
			m_actor = actor;
			m_transform = transform;
		}

		virtual void OnAttach() {};
		virtual void Start() {};
		virtual void LateStart() {};
		virtual void Update(float deltaTime) {};
		virtual void LateUpdate(float deltaTime) {};
		virtual void FixedUpdate(float deltaTime) {};
		virtual void Destroy() {};

	protected:
		World* m_world;
		Actor* m_actor;
		Transform* m_transform;

	private:
		ScriptState m_state;
	};
}

#endif //_SCRIPTABLE_H_
