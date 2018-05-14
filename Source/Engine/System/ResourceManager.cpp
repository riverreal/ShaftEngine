#include "ResourceManager.h"
#include "MeshManager.h"
#include "ShaderManager.h"
#include "FileSystem.h"
#include "../Graphics/TextureManager.h"
#include "../Graphics/MaterialManager.h"

using namespace Shaft;

Shaft::ResourceManager::ResourceManager()
{
}

Shaft::ResourceManager::~ResourceManager()
{
}

void Shaft::ResourceManager::Initialize()
{
	m_fileSystem = eastl::make_unique<FileSystem>();
	m_meshManager = eastl::make_unique<MeshManager>(m_fileSystem.get());
	m_shaderManager = eastl::make_unique<ShaderManager>(m_fileSystem.get());
	m_textureManager = eastl::make_unique<TextureManager>(m_fileSystem.get());
	m_materialManager = eastl::make_unique<MaterialManager>(m_fileSystem.get(), m_textureManager.get());
	m_meshManager->InitPrimitiveMesh();
#if SE_BUILD
	
#else
	ResDB resDB;
	m_fileSystem->DeserializeJson(m_fileSystem->GetResourcePath() + "ResDB.rdb", resDB);
	eastl::string resPath = m_fileSystem->GetResourcePath().substr(0, m_fileSystem->GetResourcePath().size() - 1);
	for (auto& texPath : resDB.tex)
	{
		m_textureManager->PrepareTexture(resPath + texPath.c_str());
	}

	for (auto& meshPath : resDB.mesh)
	{
		m_meshManager->PrepareMesh(resPath + meshPath.c_str());
	}

	for (auto& shaderPath : resDB.shd)
	{
		m_shaderManager->LoadShader(resPath + shaderPath.c_str());
	}

	for (auto& matPath : resDB.mat)
	{
		m_materialManager->LoadMaterial(resPath + matPath.c_str());
	}

	for (auto& minPath : resDB.min)
	{
		m_materialManager->LoadMaterialInstance(resPath + minPath.c_str());
	}
#endif

	m_materialManager->InitializeUniforms();
	m_textureManager->InitDefaultTextures();
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

MaterialManager & Shaft::ResourceManager::GetMaterialManager()
{
	return *m_materialManager.get();
}
