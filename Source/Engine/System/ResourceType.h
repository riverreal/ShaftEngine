#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	struct ResourceType
	{
		ResourceType() 
			:id(-1), created(false), duplicationRef("")
		{}

		uint32 id;
		bool created;
		std::string duplicationRef;
	};
}