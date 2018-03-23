#include "Vertex.h"

using namespace Shaft;

bgfx::VertexDecl Vertex::declaration;

Shaft::Vertex::Vertex()
{
}

Vertex::Vertex(float px, float py, float pz,
	float nx, float ny, float nz,
	float tx, float ty, float tz,
	float u, float v)
	:position(px, py, pz), normal(nx, ny, nz),
	tangentU(tx, ty, tz), tex(u, v)
{
}

void Shaft::Vertex::Init()
{
	declaration.begin()
		.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
		.add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float)
		.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
		.add(bgfx::Attrib::Tangent, 3, bgfx::AttribType::Float)
		.end();
}
