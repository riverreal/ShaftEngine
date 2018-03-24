#pragma once

#include <Shaft/Core.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/matrix.hpp>
#include <glm/gtx/transform.hpp>
#include "IComponent.h"

namespace Shaft
{
	struct Transform : IComponent
	{
	public:
		Transform()
			:position(0), rotation(1,0,0,0), scale(1), localMatrix(1.0f), dynamic(true)
		{}

		Vec3f position;
		glm::quat rotation;
		Vec3f scale;
		glm::tmat4x4<float, glm::highp> localMatrix;
		bool dynamic;
	};
}