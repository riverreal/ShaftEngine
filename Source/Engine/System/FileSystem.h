#pragma once

#include <Shaft/Core.h>

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
	private:
		const std::string m_packageNames[MAX_PACKAGES];
		std::string m_projectPath;
	};
}