#include "MeshManager.h"
#include "FileSystem.h"
#include "../Graphics/ModelBuilder.h"
#include "../Graphics/ShapeBuilder.h"

using namespace Shaft;

Shaft::MeshManager::MeshManager(FileSystem* fileSystem, uint32 reserveCount)
	:m_meshTypes(reserveCount),
	m_fileSystem(fileSystem),
	m_idCounter(0),
	m_cubeID(0),
	m_sphereID(0),
	m_planeID(0)
{
	//Register vertex stream declarations
	Vertex::Init();
}

Shaft::MeshManager::~MeshManager()
{
	DestroyAllBuffers();
}

uint32 Shaft::MeshManager::LoadMesh(const std::string& fileName, uint32 packNum)
{
	if (m_meshTypes.empty())
	{
		std::cout << "Couldn't find mesh. Make sure to add it to the ResDB" << std::endl;
		return 0;
	}

	uint32 id = 0;
	bool created = false;
	bool found = false;
	std::string filepath = m_fileSystem->GetPackedResourcePath(FileSystem::PackageNumber(packNum));
	filepath += fileName;
	for (auto& mesh : m_meshTypes)
	{
		if (mesh.name == filepath)
		{
			created = mesh.created;
			id = mesh.id;
			found = true;
		}
	}

	if (!found)
	{
		std::cout << "Mesh not found" << std::endl;
		return 0;
	}

	if (created)
	{
		return id;
	}

	MeshType meshType;
	meshType.name = filepath;
	meshType.id = id;

	auto meshData = ModelBuilder::CreateModel(filepath);

	uint16 stride = Vertex::declaration.getStride();
	const bgfx::Memory* vertexMem = bgfx::alloc(meshData.vertices.size() * stride);
	bx::memCopy(vertexMem->data, meshData.vertices.data(), vertexMem->size);

	const bgfx::Memory* indexMem = bgfx::alloc(meshData.indices.size() * sizeof(uint16));
	bx::memCopy(indexMem->data, meshData.indices.data(), indexMem->size);

	//Vertex buffer
	meshType.vb = bgfx::createVertexBuffer(vertexMem, Vertex::declaration);

	//Index buffer
	meshType.ib = bgfx::createIndexBuffer(indexMem);

	meshType.created = true;
	m_meshTypes[id] = meshType;
	return meshType.id;
}

uint32 Shaft::MeshManager::LoadShape(ShapeType type)
{
	switch (type)
	{
	case Shaft::Cube:
		return m_cubeID;
		break;
	case Shaft::Sphere:
		return m_sphereID;
		break;
	case Shaft::Plane:
		return m_planeID;
		break;
	default:
		return m_cubeID;
		break;
	}
	return m_cubeID;
}

std::vector<MeshType>& Shaft::MeshManager::GetMeshTypes()
{
	return m_meshTypes;
}

void Shaft::MeshManager::DestroyAllBuffers()
{
	for (auto& meshType : m_meshTypes)
	{
		if (meshType.created)
		{
			bgfx::destroy(meshType.vb);
			if (bgfx::isValid(meshType.ib))
			{
				bgfx::destroy(meshType.ib);
			}
			
		}
	}
}

void Shaft::MeshManager::PrepareMesh(const std::string & filepath)
{
	MeshType mesh;
	mesh.created = false;
	mesh.name = filepath;
	mesh.id = m_idCounter;
	m_idCounter++;
	m_meshTypes.push_back(mesh);
}

void Shaft::MeshManager::InitPrimitiveMesh()
{
	MeshType mesh;

	//Cube
	{
		mesh.name = "Cube";
		mesh.created = true;
		mesh.id = m_idCounter;
		m_cubeID = m_idCounter;
		auto meshData = ShapeBuilder::CreateCube(1.0f, 1.0f, 1.0f);
		uint16 stride = Vertex::declaration.getStride();
		const bgfx::Memory* vertexMem = bgfx::alloc(meshData.vertices.size() * stride);
		bx::memCopy(vertexMem->data, meshData.vertices.data(), vertexMem->size);
		const bgfx::Memory* indexMem = bgfx::alloc(meshData.indices.size() * sizeof(uint16));
		bx::memCopy(indexMem->data, meshData.indices.data(), indexMem->size);
		mesh.vb = bgfx::createVertexBuffer(vertexMem, Vertex::declaration);
		mesh.ib = bgfx::createIndexBuffer(indexMem);
		m_meshTypes.push_back(mesh);
		m_idCounter++;
	}

	//Sphere
	{
		mesh.name = "Sphere";
		mesh.created = true;
		mesh.id = m_idCounter;
		m_sphereID = m_idCounter;
		auto meshData = ShapeBuilder::CreateSphere(0.5f, 12, 12);
		uint16 stride = Vertex::declaration.getStride();
		const bgfx::Memory* vertexMem = bgfx::alloc(meshData.vertices.size() * stride);
		bx::memCopy(vertexMem->data, meshData.vertices.data(), vertexMem->size);
		const bgfx::Memory* indexMem = bgfx::alloc(meshData.indices.size() * sizeof(uint16));
		bx::memCopy(indexMem->data, meshData.indices.data(), indexMem->size);
		mesh.vb = bgfx::createVertexBuffer(vertexMem, Vertex::declaration);
		mesh.ib = bgfx::createIndexBuffer(indexMem);
		m_meshTypes.push_back(mesh);
		m_idCounter++;
	}

	//Plane
	{
		mesh.name = "Plane";
		mesh.created = true;
		mesh.id = m_idCounter;
		m_planeID = m_idCounter;
		auto meshData = ShapeBuilder::CreatePlane(1.0f, 1.0f, 1, 1);
		uint16 stride = Vertex::declaration.getStride();
		const bgfx::Memory* vertexMem = bgfx::alloc(meshData.vertices.size() * stride);
		bx::memCopy(vertexMem->data, meshData.vertices.data(), vertexMem->size);
		//const bgfx::Memory* indexMem = bgfx::alloc(meshData.indices.size() * sizeof(uint16));
		//bx::memCopy(indexMem->data, meshData.indices.data(), indexMem->size);
		mesh.vb = bgfx::createVertexBuffer(vertexMem, Vertex::declaration);
		mesh.ib = BGFX_INVALID_HANDLE;//bgfx::createIndexBuffer(indexMem);
		m_meshTypes.push_back(mesh);
		m_idCounter++;
	}
}
