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
	m_fileSystem = std::make_unique<FileSystem>();
	m_meshManager = std::make_unique<MeshManager>(m_fileSystem.get());
	m_shaderManager = std::make_unique<ShaderManager>(m_fileSystem.get());
	m_textureManager = std::make_unique<TextureManager>(m_fileSystem.get());
	m_materialManager = std::make_unique<MaterialManager>(m_fileSystem.get(), m_textureManager.get());
	m_meshManager->InitPrimitiveMesh();
#if SE_BUILD
	
#else
	ResDB resDB;
	m_fileSystem->DeserializeJson(m_fileSystem->GetResourcePath() + "ResDB.rdb", resDB);
	std::string resPath = m_fileSystem->GetResourcePath().substr(0, m_fileSystem->GetResourcePath().size() - 1);
	for (auto& texPath : resDB.tex)
	{
		m_textureManager->PrepareTexture(resPath + texPath);
	}

	for (auto& meshPath : resDB.mesh)
	{
		m_meshManager->PrepareMesh(resPath + meshPath);
	}

	for (auto& shaderPath : resDB.shd)
	{
		m_shaderManager->LoadShader(resPath + shaderPath);
	}

	for (auto& matPath : resDB.mat)
	{
		m_materialManager->LoadMaterial(resPath + matPath);
	}

	for (auto& minPath : resDB.min)
	{
		m_materialManager->LoadMaterialInstance(resPath + minPath);
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
