#include "SystemsManager.h"
#include "TransformSystem.h"

Shaft::SystemsManager::SystemsManager(EngineEntityManager * eManager)
	:m_transformSystem(eastl::make_unique<TransformSystem>(eManager))
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
}
