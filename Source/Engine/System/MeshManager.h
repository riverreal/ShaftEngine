#pragma once

#include <Shaft/Core.h>
#include "Misc/Vertex.h"
#include "ResourceType.h"

namespace Shaft
{
	class FileSystem;

	struct MeshType : ResourceType
	{
		bgfx::VertexBufferHandle vb;
		bgfx::IndexBufferHandle ib;
	};

	enum ShapeType
	{
		Cube,
		Sphere,
		Plane
	};

	class MeshManager
	{
		friend class ResourceManager;
	public:
		MeshManager(FileSystem* fileSystem, uint32 reserveCount = 0);
		~MeshManager();

		void InitPrimitiveMesh();
		uint32 LoadMesh(const eastl::string& fileName, uint32 packNum);
		uint32 LoadShape(ShapeType type);
		eastl::vector<MeshType>& GetMeshTypes();

	private:
		void DestroyAllBuffers();
		void PrepareMesh(const eastl::string& filepath);

	private:
		eastl::vector<MeshType> m_meshTypes;
		uint32 m_idCounter;
		uint32 m_cubeID, m_sphereID, m_planeID;
		FileSystem* m_fileSystem;
	};
}