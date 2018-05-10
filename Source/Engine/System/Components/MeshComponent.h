#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	struct MeshType;

	enum class CullingType : uint32
	{
		NoCull = 0,
		Backface = BGFX_STATE_CULL_CCW,
		Frontface = BGFX_STATE_CULL_CW
	};

	struct States
	{
		States()
			:culling(CullingType::Backface)
		{}
		CullingType culling;
	};

	struct MeshComponent : IComponent
	{
		MeshComponent(uint32 mesh)
			:meshId(mesh), matInstanceId(0)
		{}

		uint32 meshId;
		uint32 matInstanceId;
		States states;
	};
}