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
		uint32 LoadShader(std::string vsFile, std::string fsFile);
		
		std::vector<ShaderType>& GetShaderTypes();

	private:
		//Compile and create shaders in realtime
		uint32 CreateShaderTypeRT(std::string shaderTypeName, std::string vsFile, std::string fsFile);
		void DestroyAllShaders();

	private:
		std::string m_shaderPath;
		std::vector<ShaderType> m_shaderTypes;
		uint32 m_idCounter;
		FileSystem* m_fileSystem;
	};
}