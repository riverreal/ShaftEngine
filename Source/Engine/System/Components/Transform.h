#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	class Transform
	{
	public:
		Transform()
			:position(0), rotation(0), scale(1)
		{}

		Vec3f position;
		Vec3f rotation;
		Vec3f scale;
	};
}