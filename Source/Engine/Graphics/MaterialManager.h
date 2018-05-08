#pragma once

#include <Shaft/Core.h>
#include "../System/ResourceType.h"
#include <array>
#include <cereal/types/array.hpp>

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

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(shaderType, enabledTextureCount, enabledConstVecCount);
		}
	};

	struct MaterialInstance : ResourceType
	{
		MaterialInstance()
			:materialID(0)
		{
			for (auto& tex : textures)
			{
				tex = 0;
			}
		}

		uint32 materialID;
		std::array<uint32, MAX_MATERIAL_TEX> textures;
		std::array<Vec4f, MAX_MATERIAL_CONST_VEC> constVec;

		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(materialID, textures, constVec);
		}
	};

	class MaterialManager
	{
		friend class ResourceManager;
	public:
		MaterialManager(FileSystem* fileSystem);
		~MaterialManager();

		void InitializeUniforms();

		uint32 LoadMaterial(const std::string& filename, int32 packageNum);
		uint32 LoadMaterial(const std::string& filepath);
		uint32 LoadMaterialInstance(const std::string& filename, int32 packageNum);
		uint32 LoadMaterialInstance(const std::string& filepath);
		std::vector<Material>& GetMaterials();
		std::vector<MaterialInstance>& GetMaterialInstances();
		std::array<bgfx::UniformHandle, MAX_MATERIAL_CONST_VEC>& GetConstVecUniforms();
		std::array<bgfx::UniformHandle, MAX_MATERIAL_TEX>& GetTexUniforms();

	private:
		void DestroyAllMaterials();
		void DestroyAllUniforms();

	private:
		std::vector<Material> m_materials;
		std::vector<MaterialInstance> m_materialInstances;
		uint32 m_idCounter;
		uint32 m_instanceIdCounter;
		FileSystem* m_fileSystem;
		std::array<bgfx::UniformHandle, MAX_MATERIAL_CONST_VEC> m_constVecUniforms;
		std::array<bgfx::UniformHandle, MAX_MATERIAL_TEX> m_textureUniforms;
	};
}