#pragma once

#include "Transform.h"
#include "MeshComponent.h"

namespace Shaft
{
	using EngineEntityManager = entityx::EntityX<entityx::DefaultStorage, 0, Transform, MeshComponent>;
	using EngineEntity = EngineEntityManager::Entity;
}
