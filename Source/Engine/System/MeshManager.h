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
		uint32 LoadMesh(const std::string& fileName, uint32 packNum);
		uint32 LoadShape(ShapeType type);
		std::vector<MeshType>& GetMeshTypes();

	private:
		void DestroyAllBuffers();
		void PrepareMesh(const std::string& filepath);

	private:
		std::vector<MeshType> m_meshTypes;
		uint32 m_idCounter;
		uint32 m_cubeID, m_sphereID, m_planeID;
		FileSystem* m_fileSystem;
	};
}