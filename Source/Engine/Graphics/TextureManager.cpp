#include "TextureManager.h"
#include "bx/bx.h"
#include "bx/file.h"
#include "bimg/bimg.h"
#include "bimg/decode.h"
#include "../System/FileSystem.h"

using namespace Shaft;

Shaft::TextureManager::TextureManager(FileSystem* fileSystem)
	:m_idCounter(0), m_fileSystem(fileSystem)
{
	static bx::DefaultAllocator alloc;
	m_allocator = &alloc;
}

Shaft::TextureManager::~TextureManager()
{
	DestroyAllTextureHandles();
}

uint32 Shaft::TextureManager::LoadTexture(const eastl::string& fileName, int32 packNum)
{
	if (m_textures.empty())
	{
		std::cout << "Textures empty. Could not find texture: " << fileName.c_str() << std::endl;
		return 0;
	}

	uint32 id;
	bool created = false;
	bool found = false;
	eastl::string filepath = m_fileSystem->GetPackedResourcePath(FileSystem::PackageNumber(packNum));
	filepath += fileName;
	for (auto& tex : m_textures)
	{
		if (tex.name.c_str() == filepath)
		{
			found = true;
			id = tex.id;
			created = tex.created;
		}
	}

	if (!found)
	{
		std::cout << "Texture not found" << filepath.c_str() << std::endl;
		return 0;
	}

	if (created)
	{
		return id;
	}

	TextureResource texture;
	texture.name = filepath.c_str();
	texture.id = m_idCounter;

	uint32 size = 0;
	void* data = m_fileSystem->LoadMem(filepath, size);
	if (data == nullptr)
	{
		std::cout << "Texture could not be loaded: " << filepath.c_str() << std::endl;
		return 0;
	}

	bimg::ImageContainer* imageContainer = bimg::imageParse(m_allocator, data, size);
	if (imageContainer != nullptr)
	{
		const bgfx::Memory* mem = bgfx::makeRef(imageContainer->m_data, imageContainer->m_size);
		texture.tex = bgfx::createTexture2D(imageContainer->m_width, imageContainer->m_height,
			1 < imageContainer->m_numMips, imageContainer->m_numLayers,
			bgfx::TextureFormat::Enum(imageContainer->m_format), 0, mem);

		texture.info.width = imageContainer->m_width;
		texture.info.height = imageContainer->m_height;
		bgfx::setName(texture.tex, filepath.c_str());
	}

	texture.created = true;
	m_textures[id] = texture;

	return 0;
}

void Shaft::TextureManager::LoadTexture(uint32 id)
{
	auto& tex = m_textures[id];
	if (tex.created == false)
	{
		uint32 size = 0;
		void* data = m_fileSystem->LoadMem(tex.name.c_str(), size);
		if (data == nullptr)
		{
			std::cout << "Texture could not be loaded: " << tex.name.c_str() << std::endl;
			return;
		}

		bimg::ImageContainer* imageContainer = bimg::imageParse(m_allocator, data, size);
		if (imageContainer != nullptr)
		{
			const bgfx::Memory* mem = bgfx::makeRef(imageContainer->m_data, imageContainer->m_size);
			tex.tex = bgfx::createTexture2D(imageContainer->m_width, imageContainer->m_height,
				1 < imageContainer->m_numMips, imageContainer->m_numLayers,
				bgfx::TextureFormat::Enum(imageContainer->m_format), 0, mem);

			tex.info.width = imageContainer->m_width;
			tex.info.height = imageContainer->m_height;
			bgfx::setName(tex.tex, tex.name.c_str());
		}

		tex.created = true;
	}
}

eastl::vector<TextureResource>& Shaft::TextureManager::GetTextures()
{
	return m_textures;
}

void Shaft::TextureManager::InitDefaultTextures()
{
	LoadTexture("0default.jpg", 1);
}

void Shaft::TextureManager::DestroyAllTextureHandles()
{
	for (auto& texture : m_textures)
	{
		if (texture.created)
		{
			bgfx::destroy(texture.tex);
		}
	}
}

void Shaft::TextureManager::PrepareTexture(const eastl::string& filepath)
{
	TextureResource texture;
	texture.name = filepath.c_str();
	texture.id = m_idCounter;
	texture.created = false;
	m_textures.push_back(texture);
	m_idCounter += 1;
}
