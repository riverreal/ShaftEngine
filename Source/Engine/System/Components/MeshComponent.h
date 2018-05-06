#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	struct MeshType;

	struct MeshComponent : IComponent
	{
		MeshComponent(uint32 mesh)
			:meshId(mesh), matInstanceId(0)
		{}

		uint32 meshId;
		uint32 matInstanceId;
	};
}