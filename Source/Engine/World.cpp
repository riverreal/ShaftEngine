#include "World.h"

using namespace Shaft;

Shaft::World::World()
{
}

Shaft::World::~World()
{
}

const std::vector<std::unique_ptr<Actor>>& Shaft::World::GetActors()
{
	return m_actors;
}
