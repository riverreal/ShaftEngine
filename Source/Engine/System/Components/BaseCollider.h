#ifndef _BASE_COLLIDER_H_
#define _BASE_COLLIDER_H_
#pragma once

#include <Shaft/Core.h>
#include <btBulletCollisionCommon.h>

namespace Shaft
{
	class Actor;

	struct BaseCollider : public IComponent
	{
		eastl::unique_ptr<btCollisionShape> collisionShape;
		Actor* actor;
	};
}


#endif //_BASE_COLLIDER_H_