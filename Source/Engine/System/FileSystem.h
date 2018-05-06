#pragma once

#include <Shaft/Core.h>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>
#include <fstream>

#define MAX_PACKAGES 10

namespace bx
{
	struct AllocatorI;
	struct FileWriterI;
	struct FileReaderI;
}

namespace Shaft
{
	class FileSystem
	{
	public:
		enum PackageNumber
		{
			Package0,
			Package1,
			Package2,
			Package3,
			Package4,
			Package5,
			Package6,
			Package7,
			Package8,
			Package9,
		};

		FileSystem();
		~FileSystem();

		void OpenProject(std::string& path);
		void* LoadMem(const std::string& filepath, uint32& outSize);
		std::string GetBasePath();
		std::string GetResourcePath();
		std::string GetPackedResourcePath(PackageNumber packNum);
		template<class T>
		void Deserialize(const std::string& filename, T& out);
		template<class T>
		void Serialize(const std::string& filename, const T& in);
		template<class T>
		void DeserializeJson(const std::string& filename, T& out);
		template<class T>
		void SerializeJson(const std::string& filename, T& in);
		//Write to file with bx
		void WriteMem(const std::string& filepath, const bgfx::Memory* mem);

	private:
		const std::string m_packageNames[MAX_PACKAGES];
		std::string m_projectPath;
		bx::AllocatorI* m_allocator;
		bx::FileWriterI* m_fileWriter;
		bx::FileReaderI* m_fileReader;
	};

	template<class T>
	inline void FileSystem::Deserialize(const std::string& filename, T& out)
	{
		std::ifstream is(filename, std::ios::binary);
		cereal::BinaryInputArchive iarchive(is);
		iarchive(out);
	}

	template<class T>
	inline void FileSystem::Serialize(const std::string& filename, const T& in)
	{
		std::ofstream os(filename, std::ios::binary);
		cereal::BinaryOutputArchive archive(os);
		archive(in);
	}

	template<class T>
	inline void FileSystem::DeserializeJson(const std::string& filename, T & out)
	{
		std::ifstream is(filename);
		cereal::JSONInputArchive iarchive(is);
		iarchive(out);
	}

	template<class T>
	inline void FileSystem::SerializeJson(const std::string& filename, T & in)
	{
		std::ofstream os(filename);
		cereal::JSONOutputArchive archive(os);
		archive(CEREAL_NVP(in));
	}
}