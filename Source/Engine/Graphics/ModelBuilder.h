#pragma once

#include "../System/Misc/Vertex.h"
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include<d3d11.h>
#include<DirectXMath.h>


namespace Shaft
{
	class ModelBuilder
	{
	public:
		static MeshData CreateModel(std::string fileName);

	private:

	};
}