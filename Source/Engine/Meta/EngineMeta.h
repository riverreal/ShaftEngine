#pragma once

#include <Shaft/Reflection.h>
#include "../Actor.h"

namespace Shaft
{
	REFLECT_INLINE(Actor)
	{
		rttr::registration::class_<Actor>("Actor")
			.property("name", &Actor::GetName, &Actor::SetName);
	}
}