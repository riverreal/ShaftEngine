#pragma once

#include "Transform.h"
#include "MeshComponent.h"
#include "ScriptableComponent.h"
#include "CameraComponent.h"
#include "BillboardComponent.h"

namespace Shaft
{
	using EngineEntityManager = entityx::EntityX<entityx::DefaultStorage, 0, Transform, 
		MeshComponent, ScriptableComponent, CameraComponent, BillboardComponent>;
	using EngineEntity = EngineEntityManager::Entity;
}
