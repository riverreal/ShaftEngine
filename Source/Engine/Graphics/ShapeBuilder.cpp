#include "ShapeBuilder.h"

using namespace Shaft;

MeshData Shaft::PrimitiveMeshBuilder::CreateCube(float width, float height, float depth)
{
	MeshData meshData;

	Vertex v[24];

	float w2 = 0.5*width;
	float h2 = 0.5f*height;
	float d2 = 0.5f*depth;

	v[0] = Vertex(-w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[1] = Vertex(-w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[2] = Vertex(+w2, +h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[3] = Vertex(+w2, -h2, -d2, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	v[4] = Vertex(-w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[5] = Vertex(+w2, -h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[6] = Vertex(+w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[7] = Vertex(-w2, +h2, +d2, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	v[8] = Vertex(-w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[9] = Vertex(-w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[10] = Vertex(+w2, +h2, +d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	v[11] = Vertex(+w2, +h2, -d2, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);

	v[12] = Vertex(-w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[13] = Vertex(+w2, -h2, -d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[14] = Vertex(+w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[15] = Vertex(-w2, -h2, +d2, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	v[16] = Vertex(-w2, -h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[17] = Vertex(-w2, +h2, +d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[18] = Vertex(-w2, +h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
	v[19] = Vertex(-w2, -h2, -d2, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

	v[20] = Vertex(+w2, -h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	v[21] = Vertex(+w2, +h2, -d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	v[22] = Vertex(+w2, +h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
	v[23] = Vertex(+w2, -h2, +d2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);

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

MeshData Shaft::PrimitiveMeshBuilder::CreateSphere(float radius, uint32 sliceCount, uint32 stackCount)
{
	MeshData meshData;

	meshData.vertices.clear();
	meshData.indices.clear();

	Vertex topVertex(0.0f, +radius, 0.0f, 0.0f, +1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	Vertex bottomVertex(0.0f, -radius, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	meshData.vertices.push_back(topVertex);

	float phiStep = D_PI / stackCount;
	float thetaStep = 2.0f*D_PI / sliceCount;

	for (uint32 i = 1; i <= stackCount - 1; ++i)
	{
		float phi = i * phiStep;

		for (uint32 j = 0; j <= sliceCount; ++j)
		{
			float theta = j * thetaStep;

			Vertex v;

			v.position.x = radius * sinf(phi)*cosf(theta);
			v.position.y = radius * cosf(phi);
			v.position.z = radius * sinf(phi)*sinf(theta);

			v.tangentU.x = -radius * sinf(phi) * sinf(theta);
			v.tangentU.y = 0.0f;
			v.tangentU.z = +radius * sinf(phi)*cosf(theta);

			v.tangentU = v.tangentU.FastNormalize();

			v.normal = v.position.FastNormalize();

			v.tex.x = theta / D_PI;
			v.tex.y = phi / D_PI;

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

MeshData Shaft::PrimitiveMeshBuilder::CreateCylinder(float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount)
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
		float dTheta = 2.0f*D_PI / sliceCount;
		for (uint32 j = 0; j <= sliceCount; ++j)
		{
			Vertex vertex;

			float c = cosf(j*dTheta);
			float s = sinf(j*dTheta);

			vertex.position = Vec3f(r*c, y, r*s);

			vertex.tex.x = (float)j / sliceCount;
			vertex.tex.y = 1.0f - (float)i / stackCount;

			// This is unit length.
			vertex.tangentU = Vec3f(-s, 0.0f, c);

			float dr = bottomRadius - topRadius;
			Vec3f bitangent(dr*c, -height, dr*s);

			vertex.normal = (vertex.tangentU.Cross(bitangent)).FastNormalize();

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

MeshData Shaft::PrimitiveMeshBuilder::CreateQuad()
{
	MeshData meshData;

	meshData.vertices.resize(4);
	meshData.indices.resize(6);
	
	meshData.vertices[0] = Vertex(
		-1.0f, -1.0f, 0.0f,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f);

	meshData.vertices[1] = Vertex(
		-1.0f, +1.0f, 0.0f,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f);

	meshData.vertices[2] = Vertex(
		+1.0f, +1.0f, 0.0f,
		0.0f, 0.0f, -1.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f);

	meshData.vertices[3] = Vertex(
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

MeshData Shaft::PrimitiveMeshBuilder::CreatePlane(float width, float depth, uint32 m, uint32 n)
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

			meshData.vertices[i*n + j].position = Vec3f(x, 0.0f, z);
			meshData.vertices[i*n + j].normal = Vec3f(0.0f, 1.0f, 0.0f);
			meshData.vertices[i*n + j].tangentU = Vec3f(1.0f, 0.0f, 0.0f);

			meshData.vertices[i*n + j].tex.x = j * du;
			meshData.vertices[i*n + j].tex.y = i * dv;
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

void Shaft::PrimitiveMeshBuilder::Subdivide(MeshData& inOut)
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

	uint32 numTris = inputCopy.indices.size() / 3;

	for (uint32 i = 0; i < numTris; ++i)
	{
		Vertex v0 = inputCopy.vertices[inputCopy.indices[i * 3 + 0]];
		Vertex v1 = inputCopy.vertices[inputCopy.indices[i * 3 + 1]];
		Vertex v2 = inputCopy.vertices[inputCopy.indices[i * 3 + 2]];

		Vertex m0, m1, m2;

		m0.position = Vec3f(
			0.5f*(v0.position.x + v1.position.x),
			0.5f*(v0.position.y + v1.position.y),
			0.5f*(v0.position.z + v1.position.z));

		m1.position = Vec3f(
			0.5f*(v1.position.x + v2.position.x),
			0.5f*(v1.position.y + v2.position.y),
			0.5f*(v1.position.z + v2.position.z));

		m2.position = Vec3f(
			0.5f*(v0.position.x + v2.position.x),
			0.5f*(v0.position.y + v2.position.y),
			0.5f*(v0.position.z + v2.position.z));


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

void Shaft::PrimitiveMeshBuilder::BuildCylinderTopCap(MeshData& inOut, float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount)
{
	uint32 baseIndex = (uint32)inOut.vertices.size();

	float y = 0.5f*height;
	float dTheta = 2.0f*D_PI / sliceCount;

	// Duplicate cap ring vertices because the texture coordinates and normals differ.
	for (uint32 i = 0; i <= sliceCount; ++i)
	{
		float x = topRadius * cosf(i*dTheta);
		float z = topRadius * sinf(i*dTheta);

		// Scale down by the height to try and make top cap texture coord area
		// proportional to base.
		float u = x / height + 0.5f;
		float v = z / height + 0.5f;

		inOut.vertices.push_back(Vertex(x, y, z, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v));
	}

	// Cap center vertex.
	inOut.vertices.push_back(Vertex(0.0f, y, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f));

	// Index of center vertex.
	uint32 centerIndex = (uint32)inOut.vertices.size() - 1;

	for (uint32 i = 0; i < sliceCount; ++i)
	{
		inOut.indices.push_back(centerIndex);
		inOut.indices.push_back(baseIndex + i + 1);
		inOut.indices.push_back(baseIndex + i);
	}
}

void Shaft::PrimitiveMeshBuilder::BuildCylinderBottomCap(MeshData& inOut, float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount)
{
	uint32 baseIndex = (uint32)inOut.vertices.size();
	float y = -0.5f*height;

	// vertices of ring
	float dTheta = 2.0f*D_PI / sliceCount;
	for (uint32 i = 0; i <= sliceCount; ++i)
	{
		float x = bottomRadius * cosf(i*dTheta);
		float z = bottomRadius * sinf(i*dTheta);

		// Scale down by the height to try and make top cap texture coord area
		// proportional to base.
		float u = x / height + 0.5f;
		float v = z / height + 0.5f;

		inOut.vertices.push_back(Vertex(x, y, z, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, u, v));
	}

	// Cap center vertex.
	inOut.vertices.push_back(Vertex(0.0f, y, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f));

	// Cache the index of center vertex.
	uint32 centerIndex = (uint32)inOut.vertices.size() - 1;

	for (uint32 i = 0; i < sliceCount; ++i)
	{
		inOut.indices.push_back(centerIndex);
		inOut.indices.push_back(baseIndex + i);
		inOut.indices.push_back(baseIndex + i + 1);
	}
}
