#include "Actor.h"
#include "World.h"

using namespace Shaft;

Shaft::Actor::Actor(EngineEntity entity, World* world)
	:m_parent(nullptr),
	m_entity(entity),
	m_world(world),
	m_name("MyActor")
{
}

Shaft::Actor::~Actor()
{
}

void Shaft::Actor::SetName(const std::string& name)
{
	m_name = name;
}

const std::string & Shaft::Actor::GetName() const
{
	return m_name;
}

void Shaft::Actor::AddChild(Actor * child)
{
	child->SetParent(this);
	m_children.push_back(child);
}

void Shaft::Actor::RemoveChild(Actor * child)
{
	auto toRemove = std::find_if(m_children.begin(), m_children.end(), [&](Actor* actor) {
		return actor->GetEntity().id().id() == child->GetEntity().id().id();
	});

	if (toRemove == m_children.end())
	{
		std::cout << "Could not find child to remove" << std::endl;
	}
	else
	{
		m_children.erase(toRemove);
	}
}

const std::vector<Actor*>& Shaft::Actor::GetChilren() const
{
	return m_children;
}

Actor * Shaft::Actor::GetParent()
{
	return m_parent;
}

void Shaft::Actor::SetParent(Actor* parent)
{
	if (m_parent != nullptr)
	{
		
	}
}

void Shaft::Actor::Destroy()
{
	m_world->RemoveActor(this);
}

World* Shaft::Actor::GetWorld()
{
	return m_world;
}

EngineEntity& Shaft::Actor::GetEntity()
{
	return m_entity;
}

Actor* Shaft::Actor::GetRoot()
{
	return GetRooRec(this);
}

bool Shaft::Actor::GetActive()
{
	return m_active;
}

void Shaft::Actor::SetActive(bool active)
{
	m_active = active;
}

void Shaft::Actor::SetParentPtr(Actor* parent)
{
	m_parent = parent;
}

Actor* Shaft::Actor::GetRooRec(Actor* target)
{
	auto parent = target->GetParent();
	if (parent == nullptr)
	{
		return target;
	}
	return GetRooRec(parent);
}
