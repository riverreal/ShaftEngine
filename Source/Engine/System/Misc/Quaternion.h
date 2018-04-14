#pragma once

#include <Shaft/Core.h>
#include <glm/gtc/quaternion.hpp>

namespace Shaft
{
	//Only holds quaternion data
	struct Quaternion
	{
		Quaternion()
			:x(0), y(0), z(0), w(0)
		{}

		Quaternion(float qx, float qy, float qz, float qw)
			:x(qx), y(qy), z(qz), w(qw)
		{}

		//Get quaternion for calculations
		const glm::quat GetQuat() const
		{
			glm::quat quat;
			quat.x = x;
			quat.y = y;
			quat.z = z;
			quat.w = w;
			return quat;
		}

		//Set quaternion data from calculations
		void SetQuat(const glm::quat& quat)
		{
			x = quat.x;
			y = quat.y;
			z = quat.z;
			w = quat.w;
		}

		static Quaternion Identity()
		{
			return Quaternion(1, 0, 0, 0);
		}

		float x;
		float y;
		float z;
		float w;
	};
}