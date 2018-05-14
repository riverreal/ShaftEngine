#include "ShapeBuilder.h"

using namespace Shaft;

MeshData Shaft::ShapeBuilder::CreateCube(float width, float height, float depth)
{
	MeshData meshData;
	
	float w2 = 0.5f*width;
	float h2 = 0.5f*height;
	float d2 = 0.5f*depth;

	Vertex v[24];
	v[0].Set(-w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[1].Set(-w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[2].Set(+w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[3].Set(+w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	v[4].Set(-w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[5].Set(+w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[6].Set(+w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[7].Set(-w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	v[8].Set(-w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[9].Set(-w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[10].Set(+w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[11].Set(+w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	v[12].Set(-w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[13].Set(+w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[14].Set(+w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[15].Set(-w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	v[16].Set(-w2, -h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[17].Set(-w2, +h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[18].Set(-w2, +h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[19].Set(-w2, -h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	v[20].Set(+w2, -h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	v[21].Set(+w2, +h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	v[22].Set(+w2, +h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
	v[23].Set(+w2, -h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);

	meshData.vertices.assign(&v[0], &v[24]);

	uint32 i[36];
	i[0] = 0; i[1] = 1; i[2] = 2;
	i[3] = 0; i[4] = 2; i[5] = 3;

	i[6] = 4; i[7] = 5; i[8] = 6;
	i[9] = 4; i[10] = 6; i[11] = 7;

	i[12] = 8; i[13] = 9; i[14] = 10;
	i[15] = 8; i[16] = 10; i[17] = 11;

	i[18] = 12; i[19] = 13; i[20] = 14;
	i[21] = 12; i[22] = 14; i[23] = 15;

	i[24] = 16; i[25] = 17; i[26] = 18;
	i[27] = 16; i[28] = 18; i[29] = 19;

	i[30] = 20; i[31] = 21; i[32] = 22;
	i[33] = 20; i[34] = 22; i[35] = 23;
	
	meshData.indices.assign(&i[0], &i[36]);

	return meshData;
}

MeshData Shaft::ShapeBuilder::CreateSphere(float radius, uint32 sliceCount, uint32 stackCount)
{
	MeshData meshData;

	meshData.vertices.clear();
	meshData.indices.clear();

	Vertex topVertex; 
	topVertex.Set(0.0f, +radius, 0.0f, 0.0f, +1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	Vertex bottomVertex;
	bottomVertex.Set(0.0f, -radius, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	meshData.vertices.push_back(topVertex);

	float phiStep = static_cast<float>(PI) / stackCount;
	float thetaStep = 2.0f*static_cast<float>(PI) / sliceCount;

	for (uint32 i = 1; i <= stackCount - 1; ++i)
	{
		float phi = i * phiStep;

		for (uint32 j = 0; j <= sliceCount; ++j)
		{
			float theta = j * thetaStep;

			Vertex v;

			Vec3f pos;
			pos.x = v.posX = radius * sinf(phi)*cosf(theta);
			pos.y = v.posY = radius * cosf(phi);
			pos.z = v.posZ = radius * sinf(phi)*sinf(theta);

			Vec3f tangent;
			tangent.x = -radius * sinf(phi) * sinf(theta);
			tangent.y = 0.0f;
			tangent.z = +radius * sinf(phi)*cosf(theta);
			tangent = tangent.FastNormalize();

			Vec3f normal;
			normal = pos.FastNormalize();

			v.SetTangent(tangent.x, tangent.y, tangent.z);
			v.SetNormal(normal.x, normal.y, normal.z);

			v.texU = theta / static_cast<float>(PI);
			v.texV = phi / static_cast<float>(PI);

			meshData.vertices.push_back(v);
		}
	}

	meshData.vertices.push_back(bottomVertex);

	for (uint32 i = 1; i <= stackCount; ++i)
	{
		meshData.indices.push_back(0);
		meshData.indices.push_back(i + 1);
		meshData.indices.push_back(i);
	}

	uint32 baseIndex = 1;
	uint32 ringVertexCount = sliceCount + 1;
	for (uint32 i = 0; i < stackCount - 2; ++i)
	{
		for (uint32 j = 0; j < sliceCount; ++j)
		{
			meshData.indices.push_back(baseIndex + i * ringVertexCount + j);
			meshData.indices.push_back(baseIndex + i * ringVertexCount + j + 1);
			meshData.indices.push_back(baseIndex + (i + 1) * ringVertexCount + j);

			meshData.indices.push_back(baseIndex + (i + 1)*ringVertexCount + j);
			meshData.indices.push_back(baseIndex + i * ringVertexCount + j + 1);
			meshData.indices.push_back(baseIndex + (i + 1) * ringVertexCount + j + 1);
		}
	}

	uint32 southPoleIndex = (uint32)meshData.vertices.size() - 1;

	baseIndex = southPoleIndex - ringVertexCount;

	for (uint32 i = 0; i < sliceCount; ++i)
	{
		meshData.indices.push_back(southPoleIndex);
		meshData.indices.push_back(baseIndex + i);
		meshData.indices.push_back(baseIndex + i + 1);
	}

	return meshData;
}

MeshData Shaft::ShapeBuilder::CreateCylinder(float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount)
{
	MeshData meshData;

	meshData.vertices.clear();
	meshData.indices.clear();

	float stackHeight = height / stackCount;

	float radiusStep = (topRadius - bottomRadius) / stackCount;

	uint32 ringCount = stackCount + 1;

	//build stacks
	for (uint32 i = 0; i < ringCount; ++i)
	{
		float y = -0.5f*height + i * stackHeight;
		float r = bottomRadius + i * radiusStep;

		// vertices of ring
		float dTheta = 2.0f*static_cast<float>(PI) / sliceCount;
		for (uint32 j = 0; j <= sliceCount; ++j)
		{
			Vertex vertex;

			float c = cosf(j*dTheta);
			float s = sinf(j*dTheta);

			vertex.SetPorsition(r*c, y, r*s);

			vertex.texU = (float)j / sliceCount;
			vertex.texV = 1.0f - (float)i / stackCount;

			// This is unit length.
			Vec3f tangent = {-s, 0.0f, c};
			vertex.SetTangent(-s, 0.0f, c);

			float dr = bottomRadius - topRadius;
			Vec3f bitangent(dr*c, -height, dr*s);

			Vec3f normal = (tangent.Cross(bitangent)).FastNormalize();
			vertex.SetNormal(normal.x, normal.y, normal.z);

			meshData.vertices.push_back(vertex);
		}
	}

	uint32 ringVertexCount = sliceCount + 1;

	// Compute indices for each stack.
	for (uint32 i = 0; i < stackCount; ++i)
	{
		for (uint32 j = 0; j < sliceCount; ++j)
		{
			meshData.indices.push_back(i*ringVertexCount + j);
			meshData.indices.push_back((i + 1)*ringVertexCount + j);
			meshData.indices.push_back((i + 1)*ringVertexCount + j + 1);

			meshData.indices.push_back(i*ringVertexCount + j);
			meshData.indices.push_back((i + 1)*ringVertexCount + j + 1);
			meshData.indices.push_back(i*ringVertexCount + j + 1);
		}
	}

	BuildCylinderTopCap(meshData, bottomRadius, topRadius, height, sliceCount, stackCount);
	BuildCylinderBottomCap(meshData, bottomRadius, topRadius, height, sliceCount, stackCount);

	return meshData;
}

MeshData Shaft::ShapeBuilder::CreateQuad()
{
	MeshData meshData;

	meshData.vertices.resize(4);
	meshData.indices.resize(6);
	
	meshData.vertices[0].Set(
		-1.0f, -1.0f, 0.0f,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f);

	meshData.vertices[1].Set(
		-1.0f, +1.0f, 0.0f,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f);

	meshData.vertices[2].Set(
		+1.0f, +1.0f, 0.0f,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f);

	meshData.vertices[3].Set(
		+1.0f, -1.0f, 0.0f,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f);

	meshData.indices[0] = 0;
	meshData.indices[1] = 1;
	meshData.indices[2] = 2;

	meshData.indices[3] = 0;
	meshData.indices[4] = 2;
	meshData.indices[5] = 3;

	return meshData;
}

MeshData Shaft::ShapeBuilder::CreatePlane(float width, float depth, uint32 m, uint32 n)
{
	MeshData meshData;

	unsigned int vertexCount = m * n;
	unsigned int faceCount = (m - 1)*(n - 1) * 2;

	float halfWidth = 0.5f*width;
	float halfDepth = 0.5f*depth;

	float dx = width / (n - 1);
	float dz = depth / (m - 1);

	float du = 1.0f / (n - 1);
	float dv = 1.0f / (m - 1);

	meshData.vertices.resize(vertexCount);
	for (unsigned int i = 0; i < m; ++i)
	{
		float z = halfDepth - i * dz;
		for (unsigned int j = 0; j < n; ++j)
		{
			float x = -halfWidth + j * dx;

			meshData.vertices[i*n + j].SetPorsition(x, 0.0f, z);
			meshData.vertices[i*n + j].SetNormal(0.0f, 1.0f, 0.0f);
			meshData.vertices[i*n + j].SetTangent(1.0f, 0.0f, 0.0f);

			meshData.vertices[i*n + j].texU = j * du;
			meshData.vertices[i*n + j].texV = i * dv;
		}
	}

	meshData.indices.resize(faceCount * 3);

	unsigned int k = 0;
	for (unsigned int i = 0; i < m - 1; ++i)
	{
		for (unsigned int j = 0; j < n - 1; ++j)
		{
			meshData.indices[k] = i * n + j;
			meshData.indices[k + 1] = i * n + j + 1;
			meshData.indices[k + 2] = (i + 1)* n + j;
			meshData.indices[k + 3] = (i + 1) * n + j;
			meshData.indices[k + 4] = i * n + j + 1;
			meshData.indices[k + 5] = (i + 1)*n + j + 1;

			k += 6;
		}
	}

	return meshData;
}

void Shaft::ShapeBuilder::Subdivide(MeshData& inOut)
{
	MeshData inputCopy = inOut;

	inOut.vertices.resize(0);
	inOut.indices.resize(0);

	//       v1
	//       *
	//      / \
	//     /   \
	//  m0*-----*m1
	//   / \   / \
	//  /   \ /   \
	// *-----*-----*
	// v0    m2     v2

	uint32 numTris = static_cast<uint32>(inputCopy.indices.size()) / 3;

	for (uint32 i = 0; i < numTris; ++i)
	{
		Vertex v0 = inputCopy.vertices[inputCopy.indices[i * 3 + 0]];
		Vertex v1 = inputCopy.vertices[inputCopy.indices[i * 3 + 1]];
		Vertex v2 = inputCopy.vertices[inputCopy.indices[i * 3 + 2]];

		Vertex m0, m1, m2;

		m0.SetPorsition(
			0.5f*(v0.posX + v1.posX),
			0.5f*(v0.posY + v1.posY),
			0.5f*(v0.posZ + v1.posZ));

		m1.SetPorsition(
			0.5f*(v1.posX + v2.posX),
			0.5f*(v1.posY + v2.posY),
			0.5f*(v1.posZ + v2.posZ));

		m2.SetPorsition(
			0.5f*(v0.posX + v2.posX),
			0.5f*(v0.posY + v2.posY),
			0.5f*(v0.posZ + v2.posZ));


		inOut.vertices.push_back(v0);
		inOut.vertices.push_back(v1);
		inOut.vertices.push_back(v2);
		inOut.vertices.push_back(m0);
		inOut.vertices.push_back(m1);
		inOut.vertices.push_back(m2);

		inOut.indices.push_back(i * 6 + 0);
		inOut.indices.push_back(i * 6 + 3);
		inOut.indices.push_back(i * 6 + 5);

		inOut.indices.push_back(i * 6 + 3);
		inOut.indices.push_back(i * 6 + 4);
		inOut.indices.push_back(i * 6 + 5);
		
		inOut.indices.push_back(i * 6 + 5);
		inOut.indices.push_back(i * 6 + 4);
		inOut.indices.push_back(i * 6 + 2);

		inOut.indices.push_back(i * 6 + 3);
		inOut.indices.push_back(i * 6 + 1);
		inOut.indices.push_back(i * 6 + 4);
	}
}

void Shaft::ShapeBuilder::BuildCylinderTopCap(MeshData& inOut, float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount)
{
	uint32 baseIndex = (uint32)inOut.vertices.size();

	float y = 0.5f*height;
	float dTheta = 2.0f*static_cast<float>(PI) / sliceCount;

	// Duplicate cap ring vertices because the texture coordinates and normals differ.
	for (uint32 i = 0; i <= sliceCount; ++i)
	{
		float x = topRadius * cosf(i*dTheta);
		float z = topRadius * sinf(i*dTheta);

		// Scale down by the height to try and make top cap texture coord area
		// proportional to base.
		float u = x / height + 0.5f;
		float v = z / height + 0.5f;

		inOut.vertices.push_back(Vertex());
		inOut.vertices.back().Set(x, y, z, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v);
	}

	// Cap center vertex.
	inOut.vertices.push_back(Vertex());
	inOut.vertices.back().Set(0.0f, y, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f);

	// Index of center vertex.
	uint32 centerIndex = (uint32)inOut.vertices.size() - 1;

	for (uint32 i = 0; i < sliceCount; ++i)
	{
		inOut.indices.push_back(centerIndex);
		inOut.indices.push_back(baseIndex + i + 1);
		inOut.indices.push_back(baseIndex + i);
	}
}

void Shaft::ShapeBuilder::BuildCylinderBottomCap(MeshData& inOut, float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount)
{
	uint32 baseIndex = (uint32)inOut.vertices.size();
	float y = -0.5f*height;

	// vertices of ring
	float dTheta = 2.0f*static_cast<float>(PI) / sliceCount;
	for (uint32 i = 0; i <= sliceCount; ++i)
	{
		float x = bottomRadius * cosf(i*dTheta);
		float z = bottomRadius * sinf(i*dTheta);

		// Scale down by the height to try and make top cap texture coord area
		// proportional to base.
		float u = x / height + 0.5f;
		float v = z / height + 0.5f;

		inOut.vertices.push_back(Vertex());
		inOut.vertices.back().Set(x, y, z, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v);
	}

	// Cap center vertex.
	inOut.vertices.push_back(Vertex());
	inOut.vertices.back().Set(0.0f, y, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f);

	// Cache the index of center vertex.
	uint32 centerIndex = (uint32)inOut.vertices.size() - 1;

	for (uint32 i = 0; i < sliceCount; ++i)
	{
		inOut.indices.push_back(centerIndex);
		inOut.indices.push_back(baseIndex + i);
		inOut.indices.push_back(baseIndex + i + 1);
	}
}
