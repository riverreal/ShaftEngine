#include "FileSystem.h"
#include <fstream>

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
}

Shaft::FileSystem::~FileSystem()
{
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
