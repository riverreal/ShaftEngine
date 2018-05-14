#pragma once

#include <Shaft/Core.h>
#include "ResourceType.h"

#define SHADER_PACKAGE_NUM 0

namespace Shaft
{
	class FileSystem;

	struct ShaderType : ResourceType
	{
		bgfx::ProgramHandle programHandle;
	};

	class ShaderManager
	{
	public:
		ShaderManager(FileSystem* fileSystem);
		~ShaderManager();

		//vs and fs file without extension
		uint32 LoadShader(const eastl::string& vsFile, const eastl::string& fsFile);
		//Load from compiled shader
		//Both vs and fs have to have the same name
		uint32 LoadShader(const eastl::string& shd);
#if !SE_BUILD
		uint32 LoadShader(const eastl::string& vsFile, const eastl::string& fsFile, bool save);
#endif
		eastl::vector<ShaderType>& GetShaderTypes();

	private:
		//Compile and create shaders in realtime
		uint32 CreateShaderTypeRT(const eastl::string& shaderTypeName, const eastl::string& vsFile, const eastl::string& fsFile, bool save=false);
		uint32 CreateShaderType(const eastl::string& shaderTypeName, const eastl::string& vsFile, const eastl::string& fsFile);
		void DestroyAllShaders();

	private:
		eastl::string m_shaderPath;
		eastl::vector<ShaderType> m_shaderTypes;
		uint32 m_idCounter;
		FileSystem* m_fileSystem;
	};
}