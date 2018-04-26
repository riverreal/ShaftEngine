#include "TextureManager.h"
#include "bx/bx.h"
#include "bx/file.h"
#include "bimg/bimg.h"
#include "bimg/decode.h"
#include "../System/FileSystem.h"

using namespace Shaft;

class FileReader : public bx::FileReader
{
	typedef bx::FileReader super;

public:
	virtual bool open(const bx::FilePath& _filePath, bx::Error* _err) override
	{
		return super::open(_filePath, _err);
	}
};

Shaft::TextureManager::TextureManager(FileSystem* fileSystem)
	:m_idCounter(0), m_fileSystem(fileSystem)
{
	static bx::DefaultAllocator alloc;
	m_allocator = &alloc;
	m_reader = BX_NEW(m_allocator, FileReader);
}

Shaft::TextureManager::~TextureManager()
{
	DestroyAllTextureHandles();
	BX_FREE(m_allocator, m_reader);
}

uint32 Shaft::TextureManager::LoadTexture(std::string fileName, int32 packNum)
{
	std::string filepath = m_fileSystem->GetPackedResourcePath(FileSystem::PackageNumber(packNum));
	filepath += fileName;
	std::cout << m_fileSystem->GetPackedResourcePath(FileSystem::PackageNumber(packNum)) << std::endl;
	for (auto& tex : m_textures)
	{
		if (tex.duplicationRef == filepath)
		{
			std::cout << "Texture already registered" << std::endl;
			return tex.id;
		}
	}

	TextureResource texture;	
	texture.duplicationRef = filepath;
	texture.id = m_idCounter;

	uint32 size = 0;
	void* data = LoadMem(filepath, size);
	if (data == nullptr)
	{
		std::cout << "Texture could not be loaded: " << filepath << std::endl;
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
	m_textures.push_back(texture);
	m_idCounter += 1;

	return 0;
}

std::vector<TextureResource>& Shaft::TextureManager::GetTextures()
{
	return m_textures;
}

void * Shaft::TextureManager::LoadMem(std::string filepath, uint32 & outSize)
{
	if (bx::open(m_reader, filepath.c_str()))
	{
		uint32 size = static_cast<uint32>(bx::getSize(m_reader));
		void* data = BX_ALLOC(m_allocator, size);
		bx::read(m_reader, data, size);
		bx::close(m_reader);

		if (NULL != size)
		{
			outSize = size;
		}

		return data;
	}

	std::cout << "Failed to load image: " << filepath << std::endl;
	return nullptr;
}

void Shaft::TextureManager::DestroyAllTextureHandles()
{
	for (auto& texture : m_textures)
	{
		bgfx::destroy(texture.tex);
	}
}
