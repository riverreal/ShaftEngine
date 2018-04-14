#pragma once

#include <Shaft/Core.h>
#include "IComponent.h"

namespace Shaft
{
	struct Transform : IComponent
	{
		Transform()
			:position(0), rotation(1,0,0,0), scale(1), localMatrix(1.0f), dynamic(true), isDirty(true)
		{}

		const Vec3f& GetPosition() const
		{
			return position;
		}
		void SetPosition(const Vec3f& pos)
		{
			position = pos;
			isDirty = true;
		}

		const Quaternion& GetRotation() const
		{
			return rotation;
		}
		void SetRotation(const Quaternion& quat)
		{
			rotation = quat;
			isDirty = true;
		}

		const Vec3f& GetScale() const
		{
			return scale;
		}
		void SetScale(const Vec3f& sca)
		{
			scale = sca;
			isDirty = true;
		}

		Matrix localMatrix;
		bool dynamic;
		bool isDirty;

	private:
		Vec3f position;
		Quaternion rotation;
		Vec3f scale;
	};
}