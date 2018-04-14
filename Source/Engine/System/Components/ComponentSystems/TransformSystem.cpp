#include "TransformSystem.h"
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

using namespace Shaft;

Shaft::TransformSystem::TransformSystem(EngineEntityManager * eManager)
	:m_entityManager(eManager)
{
}

Shaft::TransformSystem::~TransformSystem()
{
}

void Shaft::TransformSystem::Initialize()
{
}

void Shaft::TransformSystem::Update()
{
	UpdateMatrix();
}

void Shaft::TransformSystem::UpdateMatrix()
{
	for (auto entity : m_entityManager->entities_with_components<Transform>())
	{
		Transform* transform = entity.component<Transform>();
		if (!transform->enabled)
		{
			continue;
		}

		if (transform->initialized)
		{
			if (!transform->dynamic)
			{
				continue;
			}
		}
		else //ignore dynamic if not initialized
		{
			transform->initialized = true;
		}

		if (!transform->isDirty)
		{
			continue;
		}

		auto pos = transform->GetPosition();
		glm::mat4 translate = glm::translate(glm::mat4(), glm::vec3(pos.x, pos.y, pos.z));
		glm::quat quat = transform->GetRotation().GetQuat();
		glm::mat4 rotation =  glm::toMat4(quat);
		auto sca = transform->GetScale();
		glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(sca.x, sca.y, sca.z));
		transform->localMatrix.SetMat(translate * rotation * scale);
		transform->isDirty = false;
	}
}
