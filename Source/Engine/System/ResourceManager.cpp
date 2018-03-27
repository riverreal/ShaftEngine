#include "ResourceManager.h"
#include "MeshManager.h"
#include "ShaderManager.h"

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
	m_shaderManager = std::make_unique<ShaderManager>();
}

MeshManager& Shaft::ResourceManager::GetMeshManager()
{
	return *m_meshManager.get();
}

ShaderManager& Shaft::ResourceManager::GetShaderManager()
{
	return *m_shaderManager.get();
}
