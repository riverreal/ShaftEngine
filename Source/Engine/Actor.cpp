#include "Actor.h"
#include "World.h"

using namespace Shaft;

Shaft::Actor::Actor(EngineEntity entity, World* world)
	:m_parent(nullptr),
	m_entity(entity),
	m_world(world),
	m_name("MyActor")
{
	m_transform = entity.assign<Transform>();
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
	if (child == this)
	{
		return;
	}

	child->SetParent(this);	
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
		auto i = std::distance(m_children.begin(), toRemove);
		m_children[i]->GetTransform()->SetParent(nullptr);
		m_children[i]->SetParentPtr(nullptr);
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
	if (parent == this)
	{
		return;
	}

	//First deparent if parent exists
	if (m_parent != nullptr)
	{
		m_parent->RemoveChild(this);
	}

	//Deparent
	if (parent == nullptr)
	{
		SetParentPtr(parent);
		return;
	}

	GetTransform()->SetParent(parent->GetTransform());
	SetParentPtr(parent);
	parent->m_children.push_back(this);
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
	return GetRootRec(this);
}

bool Shaft::Actor::GetActive()
{
	return m_active;
}

void Shaft::Actor::SetActive(bool active)
{
	m_active = active;
}

Transform * Shaft::Actor::GetTransform()
{
	return m_transform;
}

void Shaft::Actor::SetParentPtr(Actor* parent)
{
	m_parent = parent;
}

Actor* Shaft::Actor::GetRootRec(Actor* target)
{
	auto parent = target->GetParent();
	if (parent == nullptr)
	{
		return target;
	}
	return GetRootRec(parent);
}
