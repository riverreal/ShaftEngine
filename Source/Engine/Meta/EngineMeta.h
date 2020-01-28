#pragma once

#include <Shaft/Reflection.h>
//#include <msgpack.hpp>
#include "../Actor.h"
#include "../Graphics/MaterialManager.h"

namespace Shaft
{
	/*REFLECT_INLINE(Actor)
	{
		rttr::registration::class_<Actor>("Actor")
			.property("name", &Actor::GetName, &Actor::SetName);
	}

	REFLECT_INLINE(Material)
	{
		rttr::registration::class_<Material>("Material")
			.property("shaderType", &Material::shaderType)
			.property("enabledTextureCount", &Material::enabledTextureCount)
			.property("enabledConstVecCount", &Material::enabledConstVecCount);
	}

	REFLECT_INLINE(MaterialInstance)
	{
		rttr::registration::class_<MaterialInstance>("MaterialInstance")
			.property("materialID", &MaterialInstance::materialID)
			.property("textures", &MaterialInstance::textures)
			.property("constVec", &MaterialInstance::constVec);
	}*/
}