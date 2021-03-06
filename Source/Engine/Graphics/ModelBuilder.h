#pragma once

#include "../System/Misc/Vertex.h"
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

namespace Shaft
{
	class ModelBuilder
	{
	public:
		static MeshData CreateModel(const eastl::string& fileName);

	private:

	};
}