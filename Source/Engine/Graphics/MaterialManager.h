#pragma once

#include <Shaft/Core.h>
#include "../System/ResourceType.h"
#include <array>

namespace Shaft
{
	class FileSystem;
	struct ShaderType;

	const int32 MAX_MATERIAL_TEX = 16;
	const int32 MAX_MATERIAL_CONST_VEC = 16;

	struct Material : ResourceType
	{
		uint32 shaderType;
		std::array<uint32, MAX_MATERIAL_TEX> m_textures;
		std::array<Vec4f, MAX_MATERIAL_CONST_VEC> m_constVecs;
	};

	class MaterialManager
	{
	public:
		MaterialManager(FileSystem* fileSystem);
		~MaterialManager();

		uint32 CreateMaterial(std::string filename, int32 packageNum);
		std::vector<Material>& GetMaterials();

	private:
		void DestroyAllMaterials();

	private:
		std::vector<Material> m_materials;
		uint32 m_idCounter;
		FileSystem* m_fileSystem;
		
	};
}