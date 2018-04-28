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

uint32 Shaft::ShaderManager::LoadShader(std::string vsFile, std::string fsFile)
{
#if SE_BUILD == false
	return CreateShaderTypeRT((vsFile + ":" + fsFile), vsFile + ".sc", fsFile + ".sc");
#else
	
#endif
	std::cout << "Could not create shader";
	return 0;
}

uint32 Shaft::ShaderManager::CreateShaderTypeRT(std::string shaderTypeName, std::string vsFile, std::string fsFile)
{
	bool registered = false;
	ShaderType* shaderType = nullptr;

	for (auto& shader : m_shaderTypes)
	{
		if (shader.duplicationRef == shaderTypeName)
		{
			if (shader.created)
			{
				std::cout << "Shader found" << std::endl;
				return shader.id;
			}
			shaderType = &shader;
			registered = true;
		}
	}

	if (!registered)
	{
		//register
		ShaderType stInstance;
		stInstance.duplicationRef = shaderTypeName;
		stInstance.id = m_idCounter;
		m_shaderTypes.push_back(stInstance);
		m_idCounter++;
		shaderType = &m_shaderTypes[stInstance.id];
	}

	const bgfx::Memory* memVsh = shaderc::compileShader(shaderc::ST_VERTEX, (m_shaderPath + vsFile).c_str(), (m_shaderPath + "Include").c_str());
	bgfx::ShaderHandle vsh = bgfx::createShader(memVsh);
	const bgfx::Memory* memFsh = shaderc::compileShader(shaderc::ST_FRAGMENT, (m_shaderPath + fsFile).c_str(), (m_shaderPath + "Include").c_str());
	bgfx::ShaderHandle fsh = bgfx::createShader(memFsh);
	shaderType->created = true;
	shaderType->programHandle = bgfx::createProgram(vsh, fsh, true);
	
	return shaderType->id;
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
