#pragma once

#include "../System/Misc/Vertex.h"

namespace Shaft
{
	class PrimitiveMeshBuilder
	{
	public:
		static MeshData CreateCube(float width, float height, float depth);
		static MeshData CreateSphere(float radius, uint32 sliceCount, uint32 stackCount);
		static MeshData CreateCylinder(float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount);
		static MeshData CreateQuad();
		static MeshData CreatePlane(float width, float depth, uint32 m, uint32 n);

	private:
		static void Subdivide(MeshData& inOut);
		static void BuildCylinderTopCap(MeshData& inOut, float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount);
		static void BuildCylinderBottomCap(MeshData& inOut, float bottomRadius, float topRadius, float height, uint32 sliceCount, uint32 stackCount);
	};
}