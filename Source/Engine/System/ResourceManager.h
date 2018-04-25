#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class MeshManager;
	class ShaderManager;
	class TextureManager;
	class FileSystem;

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

	private:
		std::unique_ptr<MeshManager> m_meshManager;
		std::unique_ptr<ShaderManager> m_shaderManager;
		std::unique_ptr<TextureManager> m_textureManager;
		std::unique_ptr<FileSystem> m_fileSystem;
	};
}