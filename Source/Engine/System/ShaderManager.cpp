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

uint32 Shaft::ShaderManager::LoadShader(const std::string& vsFile, const std::string& fsFile)
{
#if SE_BUILD == false
	return CreateShaderTypeRT((vsFile + ":" + fsFile), vsFile + ".sc", fsFile + ".sc");
#else
	
#endif
	std::cout << "Could not create shader";
	return 0;
}

uint32 Shaft::ShaderManager::LoadShader(const std::string & shd)
{
	return CreateShaderType(shd, shd + ".vs", shd + ".fs");
}

#if !SE_BUILD
uint32 Shaft::ShaderManager::LoadShader(const std::string & vsFile, const std::string & fsFile, bool save)
{
	return CreateShaderTypeRT((vsFile + ":" + fsFile), vsFile + ".sc", fsFile + ".sc", save);
}
#endif

uint32 Shaft::ShaderManager::CreateShaderTypeRT(const std::string& shaderTypeName, const std::string& vsFile, const std::string& fsFile, bool save)
{
	bool registered = false;
	ShaderType* shaderType = nullptr;

	for (auto& shader : m_shaderTypes)
	{
		if (shader.name == shaderTypeName)
		{
			if (shader.created)
			{
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
		stInstance.name = shaderTypeName;
		stInstance.id = m_idCounter;
		m_shaderTypes.push_back(stInstance);
		m_idCounter++;
		shaderType = &m_shaderTypes[stInstance.id];
	}

	const bgfx::Memory* memVsh = shaderc::compileShader(shaderc::ST_VERTEX, (m_shaderPath + vsFile).c_str(), (m_shaderPath + "Include").c_str());
	bgfx::ShaderHandle vsh = bgfx::createShader(memVsh);
	const bgfx::Memory* memFsh = shaderc::compileShader(shaderc::ST_FRAGMENT, (m_shaderPath + fsFile).c_str(), (m_shaderPath + "Include").c_str());
	bgfx::ShaderHandle fsh = bgfx::createShader(memFsh);
	if (save)
	{
		auto path = m_fileSystem->GetPackedResourcePath(FileSystem::PackageNumber(SHADER_PACKAGE_NUM));
		m_fileSystem->WriteMem(path + "shader.vs", memVsh);
		m_fileSystem->WriteMem(path + "shader.fs", memFsh);
	}
	shaderType->created = true;
	shaderType->programHandle = bgfx::createProgram(vsh, fsh, true);
	
	return shaderType->id;
}

uint32 Shaft::ShaderManager::CreateShaderType(const std::string& shaderTypeName, const std::string& vsFile, const std::string& fsFile)
{
	bool registered = false;
	ShaderType* shaderType = nullptr;

	for (auto& shader : m_shaderTypes)
	{
		if (shader.name == shaderTypeName)
		{
			if (shader.created)
			{
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
		stInstance.name = shaderTypeName;
		stInstance.id = m_idCounter;
		m_shaderTypes.push_back(stInstance);
		m_idCounter++;
		shaderType = &m_shaderTypes[stInstance.id];
	}

	auto shaderPath = m_fileSystem->GetResourcePath();

	bgfx::ShaderHandle vsh;
	bgfx::ShaderHandle fsh;
	{
		uint32 size = 0;
		auto data = m_fileSystem->LoadMem(vsFile, size);
		const bgfx::Memory* memVsh = bgfx::alloc(size + 1);
		bx::memCopy(memVsh->data, data, size);
		memVsh->data[memVsh->size - 1] = '\0';
		delete data;
		vsh = bgfx::createShader(memVsh);
	}
	{
		uint32 size = 0;
		auto data = m_fileSystem->LoadMem(fsFile, size);
		const bgfx::Memory* memFsh = bgfx::alloc(size + 1);
		bx::memCopy(memFsh->data, data, size);
		memFsh->data[memFsh->size - 1] = '\0';
		delete data;
		fsh = bgfx::createShader(memFsh);
	}

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
		if (shader.created)
		{
			bgfx::destroy(shader.programHandle);
		}
	}
}
