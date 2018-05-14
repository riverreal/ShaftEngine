#pragma once

#include <Shaft/Core.h>
#include "../System/ResourceType.h"
#include <array>
#include <cereal/types/array.hpp>

namespace Shaft
{
	class FileSystem;
	class TextureManager;
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
		MaterialManager(FileSystem* fileSystem, TextureManager* texManager);
		~MaterialManager();

		void InitializeUniforms();

		uint32 LoadMaterial(const eastl::string& filename, int32 packageNum);
		uint32 LoadMaterial(const eastl::string& filepath);
		uint32 LoadMaterialInstance(const eastl::string& filename, int32 packageNum);
		uint32 LoadMaterialInstance(const eastl::string& filepath);
		eastl::vector<Material>& GetMaterials();
		eastl::vector<MaterialInstance>& GetMaterialInstances();
		eastl::array<bgfx::UniformHandle, MAX_MATERIAL_CONST_VEC>& GetConstVecUniforms();
		eastl::array<bgfx::UniformHandle, MAX_MATERIAL_TEX>& GetTexUniforms();

	private:
		void DestroyAllMaterials();
		void DestroyAllUniforms();

	private:
		eastl::vector<Material> m_materials;
		eastl::vector<MaterialInstance> m_materialInstances;
		uint32 m_idCounter;
		uint32 m_instanceIdCounter;
		FileSystem* m_fileSystem;
		TextureManager* m_textureManager;
		eastl::array<bgfx::UniformHandle, MAX_MATERIAL_CONST_VEC> m_constVecUniforms;
		eastl::array<bgfx::UniformHandle, MAX_MATERIAL_TEX> m_textureUniforms;
	};
}