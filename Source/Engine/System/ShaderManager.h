#pragma once

#include <Shaft/Core.h>
#include "ResourceType.h"

namespace Shaft
{
	struct ShaderType : ResourceType
	{

		bgfx::ProgramHandle programHandle;
	};

	class ShaderManager
	{
	public:
		ShaderManager();
		~ShaderManager();

		//Compile and create shaders in realtime (Only use in editor)
		uint32 CreateShaderTypeRT(std::string shaderTypeName, std::string vsPath, std::string fsPath);
		std::vector<ShaderType>& GetShaderTypes();

	private:
		void DestroyAllShaders();

	private:
		std::string m_includeDir;
		std::vector<ShaderType> m_shaderTypes;
		uint32 m_idCounter;
	};
}