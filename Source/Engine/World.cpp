#include "World.h"
#include "System/Components/ComponentSystems/SystemsManager.h"
#include "System/Misc/EngineConfig.h"

using namespace Shaft;

Shaft::World::World(EngineConfig& conf)
	:m_systemsManager(eastl::make_unique<SystemsManager>(&m_entities, this)),
	m_engineConfig(conf),
	m_mainCamera(nullptr)
{
	m_actors.reserve(ACTOR_RESERVE_COUNT);
}

Shaft::World::~World()
{
	RemoveAllActors();
}

void World::Initialize()
{
	m_systemsManager->InitializeSystems(m_engineConfig);
}

void Shaft::World::Update(float deltaTime)
{
	m_systemsManager->UpdateSystems(deltaTime);
	m_systemsManager->DelayedUpdate(deltaTime);
}

void Shaft::World::FixedUpdate(float deltaTime)
{
	m_systemsManager->FixedUpdate(deltaTime);
}

const eastl::vector<IDActor>& Shaft::World::GetActors()
{
	return m_actors;
}

Shaft::Actor* Shaft::World::CreateActor()
{
	return CreateActor<Actor>();
}

void Shaft::World::RemoveActor(Actor* actor)
{
	//Remove children first
	for (auto& child : actor->GetChilren())
	{
		RemoveActor(child);
	}
	
	//Deparent
	if (actor->GetParent() != nullptr)
	{
		auto parent = actor->GetParent();
		actor->SetParent(nullptr);

	}

	uint64 id = actor->GetEntity().id().id();
	actor->GetEntity().destroy();

	auto toRemove = eastl::find_if(m_actors.begin(), m_actors.end(), [id](IDActor& idActor) {
		return idActor.id == id;
	});

	if (toRemove == m_actors.end())
	{
		std::cout << "Could not find Actor to remove" << std::endl;
	}
	else
	{
		//uint32 index = toRemove - m_actors.begin();
		m_actors.erase(toRemove);
	}	
}

void Shaft::World::RemoveAllActors()
{
	for (auto& actor : m_actors)
	{
		actor.actor.get()->GetEntity().destroy();
	}

	m_actors.clear();
}

void World::SetMainCamera(Actor* cam)
{
	m_mainCamera = cam;
}

Actor* World::GetMainCamera()
{
	return m_mainCamera;
}