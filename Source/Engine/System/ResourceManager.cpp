#include "ResourceManager.h"
#include "MeshManager.h"
#include "ShaderManager.h"
#include "FileSystem.h"
#include "../Graphics/TextureManager.h"

using namespace Shaft;

Shaft::ResourceManager::ResourceManager()
{
}

Shaft::ResourceManager::~ResourceManager()
{
}

void Shaft::ResourceManager::Initialize()
{
	m_fileSystem = std::make_unique<FileSystem>();
	m_meshManager = std::make_unique<MeshManager>();
	m_shaderManager = std::make_unique<ShaderManager>(m_fileSystem.get());
	m_textureManager = std::make_unique<TextureManager>(m_fileSystem.get());
}

MeshManager& Shaft::ResourceManager::GetMeshManager()
{
	return *m_meshManager.get();
}

ShaderManager& Shaft::ResourceManager::GetShaderManager()
{
	return *m_shaderManager.get();
}

TextureManager& Shaft::ResourceManager::GetTextureManager()
{
	return *m_textureManager.get();
}

FileSystem & Shaft::ResourceManager::GetFileSystem()
{
	return *m_fileSystem.get();
}
