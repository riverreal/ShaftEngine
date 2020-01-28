#include "SystemsManager.h"
#include "TransformSystem.h"
#include "ScriptableSystem.h"
#include "CameraSystem.h"
#include "BillboardSystem.h"

#include "../../Misc/EngineConfig.h"

Shaft::SystemsManager::SystemsManager(EngineEntityManager* eManager, World* world)
	:m_transformSystem(eastl::make_unique<TransformSystem>(eManager)),
	m_scriptableSystem(eastl::make_unique<ScriptableSystem>(eManager)),
	m_cameraSystem(eastl::make_unique<CameraSystem>(eManager)),
	m_billboardSystem(eastl::make_unique<BillboardSystem>(eManager, world))
{
}

Shaft::SystemsManager::~SystemsManager()
{
}

void Shaft::SystemsManager::InitializeSystems(EngineConfig& config)
{
	m_transformSystem->Initialize();
	m_cameraSystem->Initialize((float)config.renderConfig.width, (float)config.renderConfig.height);
}

void Shaft::SystemsManager::UpdateSystems(float deltaTime)
{
	m_billboardSystem->Update();
	m_transformSystem->Update();
	m_scriptableSystem->UpdateScripts(deltaTime);
	m_cameraSystem->Update();
}

void Shaft::SystemsManager::DelayedUpdate(float deltaTime)
{
	m_scriptableSystem->DelayedUpdateScripts(deltaTime);
}

void Shaft::SystemsManager::FixedUpdate(float deltaTime)
{
	m_scriptableSystem->FixedUpdateScripts(deltaTime);
}
