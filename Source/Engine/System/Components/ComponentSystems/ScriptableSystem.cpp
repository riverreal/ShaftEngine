#include "ScriptableSystem.h"
#include "../Scriptable.h"

Shaft::ScriptableSystem::ScriptableSystem(EngineEntityManager * eManager)
	:m_entityManager(eManager)
{
}

Shaft::ScriptableSystem::~ScriptableSystem()
{
}

void Shaft::ScriptableSystem::UpdateScripts(float deltaTime)
{
	for (auto entity : m_entityManager->entities_with_components<ScriptableComponent>())
	{
		auto scriptComp = entity.component<ScriptableComponent>();
		for (auto& script : scriptComp->scripts)
		{
			switch (script.second->m_state)
			{
			case ScriptState::Start:
			{
				script.second->Start();
				script.second->m_state = LateStart;
			}
			break;

			case ScriptState::LateStart:
			{
				script.second->LateStart();
				script.second->m_state = Update;
			}
			break;

			case ScriptState::Update:
			{
				script.second->Update(deltaTime);
			}
			break;

			default:
				break;
			}
		}
	}
}

void Shaft::ScriptableSystem::DelayedUpdateScripts(float deltaTime)
{
	for (auto entity : m_entityManager->entities_with_components<ScriptableComponent>())
	{
		auto scriptComp = entity.component<ScriptableComponent>();
		for (auto& script : scriptComp->scripts)
		{
			if(script.second->m_state == ScriptState::Update)
			{
				script.second->LateUpdate(deltaTime);
			}
		}
	}
}

void Shaft::ScriptableSystem::FixedUpdateScripts(float deltaTime)
{
	for (auto entity : m_entityManager->entities_with_components<ScriptableComponent>())
	{
		auto scriptComp = entity.component<ScriptableComponent>();
		for (auto& script : scriptComp->scripts)
		{
			if (script.second->m_state == ScriptState::Update)
			{
				script.second->FixedUpdate(deltaTime);
			}
		}
	}
}
