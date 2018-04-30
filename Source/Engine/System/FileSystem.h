#pragma once

#include <Shaft/Core.h>
#include <msgpack.hpp>
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
		std::ifstream file(filename);
		std::istreambuf_iterator<char> first(file);
		std::istreambuf_iterator<char> last;
		const std::string data(first, last);

		msgpack::object_handle oh = msgpack::unpack(data.data(), data.size());
		msgpack::object obj = oh.get();
		obj.convert(out);
		//msgpack::unpacker msg;
		//msgpack::unpack(msg, data.data(), data.size());
		//msgpack::object obj = msg.get();
		//obj.convert(out);
	}

	template<class T>
	inline void FileSystem::Serialize(std::string filename, const T& in)
	{
		std::ofstream file(filename);
		msgpack::pack(&file, in);
	}
}