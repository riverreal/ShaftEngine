#include "MeshManager.h"

using namespace Shaft;

Shaft::MeshManager::MeshManager(uint32 reserveCount)
	:m_meshTypes(reserveCount),
	m_idCounter(0)
{
	//Register vertex stream declarations
	Vertex::Init();
}

Shaft::MeshManager::~MeshManager()
{
	DestroyAllBuffers();
}

uint32 Shaft::MeshManager::CreateMeshType(MeshData mData, std::string meshName)
{
	for (auto& mesh : m_meshTypes)
	{
		if (mesh.duplicationRef == meshName)
		{
			std::cout << "Mesh type already registered" << std::endl;
			return mesh.id;
		}
	}

	MeshType meshType;
	meshType.duplicationRef = meshName;
	meshType.id = m_idCounter;
	meshType.meshData = mData;

	uint16 stride = Vertex::declaration.getStride();
	const bgfx::Memory* vertexMem = bgfx::alloc(mData.vertices.size() * stride);
	bx::memCopy(vertexMem->data, mData.vertices.data(), vertexMem->size);

	const bgfx::Memory* indexMem = bgfx::alloc(mData.indices.size() * sizeof(uint16));
	bx::memCopy(indexMem->data, mData.indices.data(), indexMem->size);

	//Vertex buffer
	meshType.vb = bgfx::createVertexBuffer(vertexMem, Vertex::declaration);

	//Index buffer
	meshType.ib = bgfx::createIndexBuffer(indexMem);

	meshType.created = true;
	m_meshTypes.push_back(std::move(meshType));

	m_idCounter += 1;
	return meshType.id;
}

std::vector<MeshType>& Shaft::MeshManager::GetMeshTypes()
{
	return m_meshTypes;
}

void Shaft::MeshManager::DestroyAllBuffers()
{
	for (auto& meshType : m_meshTypes)
	{
		bgfx::destroy(meshType.vb);
		bgfx::destroy(meshType.ib);
	}
}
