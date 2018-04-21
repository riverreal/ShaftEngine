#pragma once

#include <Shaft/Core.h>
#include "../Engine/System/ResourceType.h"

namespace Shaft
{
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
	public:
		TextureManager();
		~TextureManager();

		uint32 LoadTexture(std::string fileName);
		std::vector<TextureResource>& GetTextures();
	private:
		void DestroyAllTextureHandles();

	private:
		std::vector<TextureResource> m_textures;
		uint32 m_idCounter;
	};
}