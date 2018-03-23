#pragma once

namespace Shaft
{
	struct IComponent
	{
		IComponent()
			:initialized(false), enabled(true)
		{}
		bool initialized;
		bool enabled;
	};
}