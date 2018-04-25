#include "ShaderManager.h"
#include "FileSystem.h"
#include <brtshaderc/brtshaderc.h>

using namespace Shaft;

Shaft::ShaderManager::ShaderManager(FileSystem* fileSystem)
	:m_idCounter(0),
	m_fileSystem(fileSystem)
{
	//shaders will be compiled at runtime if SE_BUILD is false
#if SE_BUILD == false
	m_shaderPath = fileSystem->GetBasePath() + "Shaders/";
#else
	m_shaderPath = fileSystem->GetPackedResourcePath(FileSystem::PackageNumber(SHADER_PACKAGE_NUM));
#endif
}

Shaft::ShaderManager::~ShaderManager()
{
	DestroyAllShaders();
}

uint32 Shaft::ShaderManager::CreateShaderTypeRT(std::string shaderTypeName, std::string vsFile, std::string fsFile)
{
	const bgfx::Memory* memVsh = shaderc::compileShader(shaderc::ST_VERTEX, (m_shaderPath + vsFile).c_str(), (m_shaderPath + "Include").c_str());
	bgfx::ShaderHandle vsh = bgfx::createShader(memVsh);
	const bgfx::Memory* memFsh = shaderc::compileShader(shaderc::ST_FRAGMENT, (m_shaderPath + fsFile).c_str(), (m_shaderPath + "Include").c_str());
	bgfx::ShaderHandle fsh = bgfx::createShader(memFsh);

	ShaderType shaderType;
	shaderType.created = true;
	shaderType.duplicationRef = shaderTypeName;
	shaderType.id = m_idCounter;
	shaderType.programHandle = bgfx::createProgram(vsh, fsh, true);
	m_shaderTypes.push_back(shaderType);

	m_idCounter++;

	return shaderType.id;
}

std::vector<ShaderType>& Shaft::ShaderManager::GetShaderTypes()
{
	return m_shaderTypes;
}

void Shaft::ShaderManager::DestroyAllShaders()
{
	for (auto& shader : m_shaderTypes)
	{
		bgfx::destroy(shader.programHandle);
	}
}
