#include "ResourceManager.h"
#include "MeshManager.h"

using namespace Shaft;

Shaft::ResourceManager::ResourceManager()
{
}

Shaft::ResourceManager::~ResourceManager()
{
}

void Shaft::ResourceManager::Initialize()
{
	//TODO: reserve count for mesh manager
	m_meshManager = std::make_unique<MeshManager>();
}



MeshManager& Shaft::ResourceManager::GetMeshManager()
{
	return *m_meshManager.get();
}
