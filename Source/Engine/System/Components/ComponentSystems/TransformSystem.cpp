#include "TransformSystem.h"
#include <glm/glm.hpp>

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
		
		glm::mat4 translate = glm::translate(glm::mat4(), glm::vec3(transform->position.x, transform->position.y, transform->position.z));
		glm::mat4 rotation =  glm::toMat4(transform->rotation);
		glm::mat4 scale = glm::scale(glm::vec3(transform->scale.x, transform->scale.x, transform->scale.x));
		
		transform->localMatrix = translate * rotation * scale;
	}
}
