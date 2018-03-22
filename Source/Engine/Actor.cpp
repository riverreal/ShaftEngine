#include "Actor.h"

using namespace Shaft;

Shaft::Actor::Actor(EngineEntity entity)
	:m_parent(nullptr),
	m_entity(entity)
{
}

Shaft::Actor::~Actor()
{
}

void Shaft::Actor::SetName(std::string name)
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

EngineEntity& Shaft::Actor::GetEntity()
{
	return m_entity;
}
