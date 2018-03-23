#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	struct Vertex
	{
		Vertex();
		Vertex(float px, float py, float pz,
			float nx, float ny, float nz,
			float tx, float ty, float tz,
			float u, float v);

		//Declares vertex stream
		static void Init();

		Vec3f position;
		Vec3f normal;
		Vec2f tex;
		Vec3f tangentU;
		static bgfx::VertexDecl declaration;
	};

	struct MeshData
	{
		std::vector<Vertex> vertices;
		std::vector<uint32> indices;
	};
}