#include "MeshManager.h"

Shaft::MeshManager::MeshManager(uint32 reserveCount)
	:m_meshTypes(reserveCount),
	m_idCounter(1)
{
	//Register vertex stream declarations
	Vertex::Init();
}

Shaft::MeshManager::~MeshManager()
{
}

uint32 Shaft::MeshManager::CreateMeshType(MeshData mData, std::string meshName)
{
	for (auto& mesh : m_meshTypes)
	{
		if (mesh.duplicationRef == meshName)
		{
			std::cout << "Mesh type already created" << std::endl;
			return -1;
		}
	}

	MeshType meshType;
	meshType.duplicationRef = meshName;
	meshType.id = m_idCounter;
	meshType.meshData = std::move(mData);

	//Vertex buffer
	meshType.vb = bgfx::createVertexBuffer(bgfx::makeRef(meshType.meshData.vertices.data(),
		sizeof(meshType.meshData.vertices.data())), 
		Vertex::declaration);

	//Index buffer
	meshType.ib = bgfx::createIndexBuffer(bgfx::makeRef(meshType.meshData.indices.data(),
		sizeof(meshType.meshData.indices.data())));

	meshType.created = true;
	m_meshTypes.push_back(std::move(meshType));

	m_idCounter += 1;
	return meshType.id;
}
