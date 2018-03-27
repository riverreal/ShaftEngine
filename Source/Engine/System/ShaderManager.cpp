#include "ShaderManager.h"
#include <brtshaderc/brtshaderc.h>

using namespace Shaft;

Shaft::ShaderManager::ShaderManager()
	:m_idCounter(0),
	m_includeDir("../../../Dependencies/bgfx/src")
{
}

Shaft::ShaderManager::~ShaderManager()
{
	DestroyAllShaders();
}

uint32 Shaft::ShaderManager::CreateShaderTypeRT(std::string shaderTypeName, std::string vsPath, std::string fsPath)
{
	const bgfx::Memory* memVsh = shaderc::compileShader(shaderc::ST_VERTEX, vsPath.c_str(), m_includeDir.c_str());
	bgfx::ShaderHandle vsh = bgfx::createShader(memVsh);
	const bgfx::Memory* memFsh = shaderc::compileShader(shaderc::ST_FRAGMENT, fsPath.c_str(), m_includeDir.c_str());
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
