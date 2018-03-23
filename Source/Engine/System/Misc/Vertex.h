#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	struct Vertex
	{
		Vertex() {}
		Vertex( float px, float py, float pz,
				float nx, float ny, float nz,
				float tx, float ty, float tz,
				float u, float v)
			:position(px, py, pz), normal(nx, ny, nz),
			tangentU(tx, ty, tz), tex(u, v)
		{}

		//Declares vertex stream
		static void Init()
		{
			sm_decl.begin()
				.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
				.add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float)
				.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
				.add(bgfx::Attrib::Tangent, 3, bgfx::AttribType::Float)
				.end();
		}

		Vec3f position;
		Vec3f normal;
		Vec2f tex;
		Vec3f tangentU;
		static bgfx::VertexDecl sm_decl;
	};

	struct MeshData
	{
		std::vector<Vertex> vertices;
		std::vector<uint32> indices;
	};
}