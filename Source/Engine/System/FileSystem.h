#pragma once

#include <Shaft/Core.h>
#include <cereal/archives/binary.hpp>
#include <cereal/types/memory.hpp>
#include <fstream>

#define MAX_PACKAGES 10

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

		std::string GetBasePath();
		std::string GetResourcePath();
		std::string GetPackedResourcePath(PackageNumber packNum);
		//Deserializes from a serialized file
		template<class T>
		void Deserialize(std::string filename, T& out);
		//Serializes a msgpack defined class into a file
		template<class T>
		void Serialize(std::string filename, const T& in);

	private:
		const std::string m_packageNames[MAX_PACKAGES];
		std::string m_projectPath;
	};

	template<class T>
	inline void FileSystem::Deserialize(std::string filename, T& out)
	{
		std::ifstream is(filename);
		cereal::BinaryInputArchive iarchive(is);
		iarchive(out);
	}

	template<class T>
	inline void FileSystem::Serialize(std::string filename, const T& in)
	{
		std::ofstream os(filename, std::ios::binary);
		cereal::BinaryOutputArchive archive(os);
		archive(in);
	}
}