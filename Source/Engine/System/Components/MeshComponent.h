#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	struct MeshComponent : IComponent
	{
		MeshComponent(uint32 mId)
			:meshId(mId)
		{}

		uint32 meshId;
	};
}