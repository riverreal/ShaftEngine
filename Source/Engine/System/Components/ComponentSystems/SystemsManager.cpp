#include "SystemsManager.h"
#include "TransformSystem.h"
#include "ScriptableSystem.h"

Shaft::SystemsManager::SystemsManager(EngineEntityManager* eManager)
	:m_transformSystem(eastl::make_unique<TransformSystem>(eManager)),
	m_scriptableSystem(eastl::make_unique<ScriptableSystem>(eManager))
{
}

Shaft::SystemsManager::~SystemsManager()
{
}

void Shaft::SystemsManager::InitializeSystems()
{
	m_transformSystem->Initialize();
}

void Shaft::SystemsManager::UpdateSystems(float deltaTime)
{
	m_transformSystem.get()->Update();
	m_scriptableSystem.get()->UpdateScripts(deltaTime);
}

void Shaft::SystemsManager::DelayedUpdate(float deltaTime)
{
	m_scriptableSystem.get()->DelayedUpdateScripts(deltaTime);
}

void Shaft::SystemsManager::FixedUpdate(float deltaTime)
{
	m_scriptableSystem.get()->FixedUpdateScripts(deltaTime);
}
