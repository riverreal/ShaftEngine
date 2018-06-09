#ifndef _SCRIPTABLE_COMPONENT_H_
#define _SCRIPTABLE_COMPONENT_H_
#pragma once

#include <Shaft/Core.h>
#include <typeinfo>

namespace Shaft
{
	class Scriptable;

	struct ScriptableComponent : IComponent
	{
		eastl::unordered_map<const std::type_info*, eastl::unique_ptr<Scriptable>> scripts;
	};
}

#endif //_SCRIPTABLE_COMPONENT_H_
