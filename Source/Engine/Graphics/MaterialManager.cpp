#include "MaterialManager.h"
#include "../System/ShaderManager.h"
#include "../System/FileSystem.h"
#include "TextureManager.h"

using namespace Shaft;

Shaft::MaterialManager::MaterialManager(FileSystem * fileSystem, TextureManager* texManager)
	:m_fileSystem(fileSystem), m_idCounter(0), m_instanceIdCounter(0), m_textureManager(texManager)
{
	for (auto& uniform : m_constVecUniforms)
	{
		uniform = BGFX_INVALID_HANDLE;
	}
	for (auto& uniform : m_textureUniforms)
	{
		uniform = BGFX_INVALID_HANDLE;
	}
}

Shaft::MaterialManager::~MaterialManager()
{
	DestroyAllMaterials();
	DestroyAllUniforms();
}

void Shaft::MaterialManager::InitializeUniforms()
{
	for (int32 i = 0; i < MAX_MATERIAL_CONST_VEC; ++i)
	{
		std::string name;
		name = "u_constVec" + (i < 10 ? ("0" + std::to_string(i)) : (std::to_string(i)));
		m_constVecUniforms[i] = bgfx::createUniform(name.c_str(), bgfx::UniformType::Vec4);
	}

	for (int32 i = 0; i < MAX_MATERIAL_TEX; ++i)
	{
		std::string name;
		name = "t_tex" + (i < 10 ? ("0" + std::to_string(i)) : (std::to_string(i)));
		m_textureUniforms[i] = bgfx::createUniform(name.c_str(), bgfx::UniformType::Int1);
	}
}

uint32 Shaft::MaterialManager::LoadMaterial(const std::string& filename, int32 packageNum)
{
	std::string path = m_fileSystem->GetPackedResourcePath(FileSystem::PackageNumber(packageNum));
	path += filename;
	return LoadMaterial(path);
}

uint32 Shaft::MaterialManager::LoadMaterial(const std::string& filepath)
{
	for (auto& mate : m_materials)
	{
		if (mate.name == filepath)
		{
			return mate.id;
		}
	}

	Material mat;
	mat.name = filepath;
	mat.id = m_idCounter;
	m_fileSystem->Deserialize(filepath, mat);
	m_materials.push_back(mat);
	m_idCounter += 1;
	return mat.id;
}

uint32 Shaft::MaterialManager::LoadMaterialInstance(const std::string& filename, int32 packageNum)
{
	std::string path = m_fileSystem->GetPackedResourcePath(FileSystem::PackageNumber(packageNum));
	path += filename;
	return LoadMaterialInstance(path);
}

uint32 Shaft::MaterialManager::LoadMaterialInstance(const std::string& filepath)
{
	for (auto& mate : m_materialInstances)
	{
		if (mate.name == filepath)
		{
			return mate.id;
		}
	}

	MaterialInstance mat;
	mat.name = filepath;
	mat.id = m_instanceIdCounter;
	m_fileSystem->Deserialize(filepath, mat);
	m_materialInstances.push_back(mat);
	m_instanceIdCounter += 1;
	
	for (auto texID : mat.textures)
	{
		if (texID != 0)
		{
			m_textureManager->LoadTexture(texID);
		}
	}

	return mat.id;
}

std::vector<Material>& Shaft::MaterialManager::GetMaterials()
{
	return m_materials;
}

std::vector<MaterialInstance>& Shaft::MaterialManager::GetMaterialInstances()
{
	return m_materialInstances;
}

std::array<bgfx::UniformHandle, MAX_MATERIAL_CONST_VEC>& Shaft::MaterialManager::GetConstVecUniforms()
{
	return m_constVecUniforms;
}

std::array<bgfx::UniformHandle, MAX_MATERIAL_TEX>& Shaft::MaterialManager::GetTexUniforms()
{
	return m_textureUniforms;
}

void Shaft::MaterialManager::DestroyAllMaterials()
{
}

void Shaft::MaterialManager::DestroyAllUniforms()
{
	for (auto& uni : m_constVecUniforms)
	{
		bgfx::destroy(uni);
	}

	for (auto& uni : m_textureUniforms)
	{
		bgfx::destroy(uni);
	}
}