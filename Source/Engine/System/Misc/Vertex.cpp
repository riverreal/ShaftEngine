#include "Vertex.h"
#include "Vector.h"

using namespace Shaft;

bgfx::VertexDecl Vertex::declaration;

Shaft::Vertex::Vertex()
{
}

Vertex::Vertex(float px, float py, float pz,
	float nx, float ny, float nz,
	float tx, float ty, float tz,
	float u, float v)
	:posX(px), posY(py), posZ(pz),
	normal(Color::GetNormalRGBA8(nx, ny, nz)),
	tangent(Color::GetNormalRGBA8(tx, ty, tz)),
	texU(u), texV(v)
{
}

void Shaft::Vertex::SetPorsition(float px, float py, float pz)
{
	posX = px;
	posY = py;
	posZ = pz;
}

void Shaft::Vertex::SetNormal(float nx, float ny, float nz)
{
	normal = Color::GetNormalRGBA8(nx, ny, nz);
}

void Shaft::Vertex::SetTangent(float tx, float ty, float tz)
{
	tangent = Color::GetNormalRGBA8(tx, ty, tz);
}

void Shaft::Vertex::Init()
{
	declaration.begin()
		.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
		.add(bgfx::Attrib::Normal, 4, bgfx::AttribType::Uint8, true, true)
		.add(bgfx::Attrib::Tangent, 4, bgfx::AttribType::Uint8, true, true)
		.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float, true, true)
		.end();
}
