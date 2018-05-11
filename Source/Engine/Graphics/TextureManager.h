#pragma once

#include <Shaft/Core.h>
#include "../Engine/System/ResourceType.h"

namespace bx
{
	struct AllocatorI;
	struct FileReaderI;
}

namespace Shaft
{
	class FileSystem;
	
	struct TextureInfo
	{
		int32 width;
		int32 height;
		int32 channels;
	};

	struct TextureResource : ResourceType
	{
		bgfx::TextureHandle tex;
		TextureInfo info;
	};

	class TextureManager
	{
		friend class ResourceManager;

	public:
		TextureManager(FileSystem* fileSystem);
		~TextureManager();

		uint32 LoadTexture(const std::string& fileName, int32 packNum);
		void LoadTexture(uint32 id);
		std::vector<TextureResource>& GetTextures();
		void InitDefaultTextures();

	private:
		void DestroyAllTextureHandles();
		void PrepareTexture(const std::string& filepath);

	private:
		std::vector<TextureResource> m_textures;
		uint32 m_idCounter;
		bx::AllocatorI* m_allocator;
		bx::FileReaderI* m_reader;
		FileSystem* m_fileSystem;
	};
}