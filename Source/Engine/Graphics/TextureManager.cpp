#include "TextureManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace Shaft;

Shaft::TextureManager::TextureManager()
	:m_idCounter(0)
{
}

Shaft::TextureManager::~TextureManager()
{
	DestroyAllTextureHandles();
}

uint32 Shaft::TextureManager::LoadTexture(std::string fileName)
{
	bgfx::TextureHandle handle = BGFX_INVALID_HANDLE;
	int x, y, n;
	//    unsigned char *data = stbi_load(filename, &x, &y, &n, 0);
	//    // ... process data if not NULL ...
	//    // ... x = width, y = height, n = # 8-bit components per pixel ...
	//    // ... replace '0' with '1'..'4' to force that many components per pixel
	//    // ... but 'n' will always be the number that it would have been if you said 0
	//    stbi_image_free(data)

	return 0;
}

std::vector<TextureResource>& Shaft::TextureManager::GetTextures()
{
	return m_textures;
}

void Shaft::TextureManager::DestroyAllTextureHandles()
{
	for (auto& texture : m_textures)
	{
		bgfx::destroy(texture.tex);
	}
}
