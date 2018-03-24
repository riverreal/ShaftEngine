#pragma once

#include <Shaft/Core.h>
#include "Misc/Vertex.h"

namespace Shaft
{
	struct MeshType
	{
		MeshType() :created(false),id(0), duplicationRef(""){}
		uint32 id;
		bool created;
		std::string duplicationRef;
		bgfx::VertexBufferHandle vb;
		bgfx::IndexBufferHandle ib;
		MeshData meshData;
	};

	class MeshManager
	{
	public:
		MeshManager(uint32 reserveCount = 0);
		~MeshManager();

		//Create a static mesh type
		uint32 CreateMeshType(MeshData mData, std::string meshName);
		std::vector<MeshType>& GetMeshTypes();
	private:
		void DestroyAllBuffers();

	private:
		std::vector<MeshType> m_meshTypes;
		uint32 m_idCounter;
	};
}