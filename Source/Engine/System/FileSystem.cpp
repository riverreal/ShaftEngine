#include "FileSystem.h"
#include <fstream>
#include <bx/readerwriter.h>
#include <bx/file.h>

Shaft::FileSystem::FileSystem()
	:m_packageNames{ "package0","package1","package2","package3","package4"
			,"package5" ,"package6" ,"package7" ,"package8" ,"package9" }
{
	std::string projectPath;
#if SE_BUILD == false
	projectPath = "../../";
#else
	projectPath = "Resource/";
#endif

	OpenProject(projectPath);

	static bx::DefaultAllocator alloc;
	m_allocator = &alloc;
	m_fileWriter = BX_NEW(m_allocator, bx::FileWriter);
	m_fileReader = BX_NEW(m_allocator, bx::FileReader);
}

Shaft::FileSystem::~FileSystem()
{
	BX_FREE(m_allocator, m_fileWriter);
	BX_FREE(m_allocator, m_fileReader);
}

void Shaft::FileSystem::OpenProject(std::string& path)
{
#if SE_BUILD == false
	std::ofstream stream(path + "FSP.sep");
	stream << "File System Project";
#else

#endif
	m_projectPath = path;
}

void * Shaft::FileSystem::LoadMem(const std::string& filepath, uint32 & outSize)
{
	if (bx::open(m_fileReader, filepath.c_str()))
	{
		uint32 size = static_cast<uint32>(bx::getSize(m_fileReader));
		void* data = BX_ALLOC(m_allocator, size);
		bx::read(m_fileReader, data, size);
		bx::close(m_fileReader);

		if (NULL != size)
		{
			outSize = size;
		}

		return data;
	}

	std::cout << "Failed to load to memory: " << filepath << std::endl;
	return nullptr;
}

std::string Shaft::FileSystem::GetBasePath()
{
	std::string basePath;
#if SE_BUILD == false
	basePath = m_projectPath;
#else
	basePath = m_projectPath + "../";
#endif
	return basePath;
}

std::string Shaft::FileSystem::GetResourcePath()
{
	return GetBasePath() + "Resource/";
}

std::string Shaft::FileSystem::GetPackedResourcePath(PackageNumber packNum)
{
	return GetResourcePath() + m_packageNames[(int32)packNum] + "/";
}

void Shaft::FileSystem::WriteMem(const std::string& filepath, const bgfx::Memory* mem)
{
	std::cout << filepath << std::endl;
	std::ofstream os(filepath, std::fstream::binary | std::fstream::out);
	os.write((char*)mem->data, mem->size);
	os.close();
	bx::write(m_fileWriter, mem->data, mem->size);
}
