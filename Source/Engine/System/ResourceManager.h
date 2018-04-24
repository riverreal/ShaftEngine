#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class MeshManager;
	class ShaderManager;
	class TextureManager;

	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

		void Initialize();

		MeshManager& GetMeshManager();
		ShaderManager& GetShaderManager();
		TextureManager& GetTextureManager();

	private:
		std::unique_ptr<MeshManager> m_meshManager;
		std::unique_ptr<ShaderManager> m_shaderManager;
		std::unique_ptr<TextureManager> m_textureManager;
	};
}