#pragma once

#include <Shaft/Core.h>
#include <cereal/types/vector.hpp>

namespace Shaft
{
	class MeshManager;
	class ShaderManager;
	class TextureManager;
	class FileSystem;
	class MaterialManager;

	struct ResDB
	{
		std::vector<std::string> tex;
		std::vector<std::string> mesh;
		std::vector<std::string> shd;
		std::vector<std::string> mat;
		std::vector<std::string> min;

		template<class Archive>
		void serialize(Archive& archive)
		{
			archive(CEREAL_NVP(tex), CEREAL_NVP(mesh), CEREAL_NVP(shd), CEREAL_NVP(mat), CEREAL_NVP(min));
		}
	};

	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

		void Initialize();

		MeshManager& GetMeshManager();
		ShaderManager& GetShaderManager();
		TextureManager& GetTextureManager();
		FileSystem& GetFileSystem();
		MaterialManager& GetMaterialManager();

	private:
		std::unique_ptr<MeshManager> m_meshManager;
		std::unique_ptr<ShaderManager> m_shaderManager;
		std::unique_ptr<TextureManager> m_textureManager;
		std::unique_ptr<FileSystem> m_fileSystem;
		std::unique_ptr<MaterialManager> m_materialManager;
	};
}