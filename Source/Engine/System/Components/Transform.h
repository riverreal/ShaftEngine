#pragma once

#include <Shaft/Core.h>
#include "IComponent.h"

namespace Shaft
{
	struct Transform : IComponent
	{
		Transform()
			:position(0), rotation(0,0,0,1), scale(1), 
			localMatrix(1.0f), worldMatrix(1.0f), worldBuilt(false),
			dynamic(true), isDirty(true), parent(nullptr)
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

		void SetParent(Transform* transf)
		{
			parent = transf;
			worldBuilt = false;
			isDirty = true;
		}

		Transform* GetParent()
		{
			return parent;
		}

		Matrix localMatrix;
		Matrix worldMatrix;
		bool dynamic;
		bool isDirty;
		bool worldBuilt;

	private:
		Vec3f position;
		Quaternion rotation;
		Vec3f scale;
		Transform* parent;
	};
}