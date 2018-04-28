#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class MeshManager;
	class ShaderManager;
	class TextureManager;
	class FileSystem;
	class MaterialManager;

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