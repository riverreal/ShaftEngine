#include "Actor.h"
#include <rttr/registration>

using namespace Shaft;

Shaft::Actor::Actor(EngineEntity entity, World* world)
	:m_parent(nullptr),
	m_entity(entity),
	m_world(world)
{
}

Shaft::Actor::~Actor()
{
	std::cout << "Destroy Actor: " << m_name << std::endl;
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
	m_children.push_back(child);
}

const std::vector<Actor*>& Shaft::Actor::GetChilren() const
{
	return m_children;
}

void Shaft::Actor::SetParent(Actor * parent)
{
	m_parent = parent;
}

World * Shaft::Actor::GetWorld()
{
	return m_world;
}

EngineEntity& Shaft::Actor::GetEntity()
{
	return m_entity;
}

RTTR_REGISTRATION
{
	rttr::registration::class_<Actor>("Actor")
		.property("name", &Actor::GetName, &Actor::SetName);
}