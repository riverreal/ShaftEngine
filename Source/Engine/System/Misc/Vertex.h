#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	struct Vertex
	{
		void Set(float px, float py, float pz,
			float nx, float ny, float nz,
			float tx, float ty, float tz,
			float u, float v);

		void SetPorsition(float px, float py, float pz);
		void SetNormal(float nx, float ny, float nz);
		void SetTangent(float tx, float ty, float tz);

		//Declares vertex stream
		static void Init();

		float posX;
		float posY;
		float posZ;
		float texU;
		float texV;
		uint32 normal;
		uint32 tangent;
		static bgfx::VertexDecl declaration;
	};

	struct MeshData
	{
		eastl::vector<Vertex> vertices;
		eastl::vector<uint16> indices;
	};
}