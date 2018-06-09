#pragma once

#include "Transform.h"
#include "MeshComponent.h"
#include "ScriptableComponent.h"

namespace Shaft
{
	using EngineEntityManager = entityx::EntityX<entityx::DefaultStorage, 0, Transform, 
		MeshComponent, ScriptableComponent>;
	using EngineEntity = EngineEntityManager::Entity;
}
