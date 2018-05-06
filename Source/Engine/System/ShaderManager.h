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
		uint32 LoadShader(const std::string& vsFile, const std::string& fsFile);
		//Load from compiled shader
		//Both vs and fs have to have the same name
		uint32 LoadShader(const std::string& shd);
#if !SE_BUILD
		uint32 LoadShader(const std::string& vsFile, const std::string& fsFile, bool save);
#endif
		std::vector<ShaderType>& GetShaderTypes();

	private:
		//Compile and create shaders in realtime
		uint32 CreateShaderTypeRT(const std::string& shaderTypeName, const std::string& vsFile, const std::string& fsFile, bool save=false);
		uint32 CreateShaderType(const std::string& shaderTypeName, const std::string& vsFile, const std::string& fsFile);
		void DestroyAllShaders();

	private:
		std::string m_shaderPath;
		std::vector<ShaderType> m_shaderTypes;
		uint32 m_idCounter;
		FileSystem* m_fileSystem;
	};
}