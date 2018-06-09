#ifndef _BOX_COLLIDER_H_
#define _BOX_COLLIDER_H_
#pragma once

#include "BaseCollider.h"

namespace Shaft
{
	class BoxCollider : BaseCollider
	{
		BoxCollider()
			:extents(0.0f)
		{}

		//Box extents, will be calculated from transform if not set
		Vec3f extents;
	};
}

#endif //_BOX_COLLIDER_H_