#pragma once

#include <Shaft/Core.h>
#include "../System/ResourceType.h"
#include <array>
#include <msgpack.hpp>

namespace Shaft
{
	class FileSystem;
	struct ShaderType;

	const int32 MAX_MATERIAL_TEX = 16;
	const int32 MAX_MATERIAL_CONST_VEC = 16;

	struct Material : ResourceType
	{
		Material()
			:shaderType(0), enabledTextureCount(0), enabledConstVecCount(0)
		{}
		uint32 shaderType;
		uint32 enabledTextureCount;
		uint32 enabledConstVecCount;
		//MSGPACK_DEFINE(shaderType, enabledTextureCount, enabledConstVecCount);
	};

	struct MaterialInstance
	{
		MaterialInstance()
			:materialID(0)
		{
			for (int32 i = 0; i < MAX_MATERIAL_TEX; ++i)
			{
				textures[i] = 0;
			}
		}
		uint32 materialID;
		std::array<uint32, MAX_MATERIAL_TEX> textures;
		std::array<Vec3f, MAX_MATERIAL_CONST_VEC> constVec;
		//MSGPACK_DEFINE(materialID, textures, constVec);
	};

	class MaterialManager
	{
	public:
		MaterialManager(FileSystem* fileSystem);
		~MaterialManager();

		uint32 LoadMaterial(std::string filename, int32 packageNum);
		std::vector<Material>& GetMaterials();

	private:
		void DestroyAllMaterials();

	private:
		std::vector<Material> m_materials;
		uint32 m_idCounter;
		FileSystem* m_fileSystem;
	};
}