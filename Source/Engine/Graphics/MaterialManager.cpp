#include "MaterialManager.h"
#include "../System/ShaderManager.h"
#include "../System/FileSystem.h"

using namespace Shaft;

Shaft::MaterialManager::MaterialManager(FileSystem * fileSystem)
	:m_fileSystem(fileSystem), m_idCounter(0)
{
}

Shaft::MaterialManager::~MaterialManager()
{
	DestroyAllMaterials();
}

uint32 Shaft::MaterialManager::CreateMaterial(std::string filename, int32 packageNum)
{
	std::string path = m_fileSystem->GetPackedResourcePath(FileSystem::PackageNumber(packageNum));

	//Open file and deserialize


	Material mat;
	mat.id = m_idCounter;
	m_materials.push_back(mat);
	m_idCounter++;
	return mat.id;
}

std::vector<Material>& Shaft::MaterialManager::GetMaterials()
{
	return m_materials;
}

void Shaft::MaterialManager::DestroyAllMaterials()
{
}
