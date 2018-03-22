#pragma once

#include "Transform.h"

namespace Shaft
{
	using EngineEntityManager = entityx::EntityX<entityx::DefaultStorage, 0, Transform>;
	using EngineEntity = EngineEntityManager::Entity;
}
