#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	struct ResourceType
	{
		ResourceType() 
			:id(-1), created(false), name("")
		{}

		uint32 id;
		bool created;
		std::string name;
	};
}