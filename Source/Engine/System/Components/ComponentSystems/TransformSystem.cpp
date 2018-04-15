#include "TransformSystem.h"
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>

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
	//Update local matrix first
	LocalMatrixPass();
	//Then the world matrix if needed
	WorldMatrixPass();
}

void Shaft::TransformSystem::LocalMatrixPass()
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
		glm::mat4 rotation = glm::toMat4(quat);
		auto sca = transform->GetScale();
		glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(sca.x, sca.y, sca.z));
		transform->localMatrix.SetMat(translate * rotation * scale);

		if (transform->GetParent() == nullptr)
		{
			transform->worldMatrix = transform->localMatrix;
			transform->worldBuilt = true;
		}
	}
}

void Shaft::TransformSystem::WorldMatrixPass()
{
	bool complete = false;
	auto transforms = m_entityManager->entities_with_components<Transform>();
	while (!complete)
	{
		complete = true;
		for (auto entity : transforms)
		{
			Transform* transform = entity.component<Transform>();
			if (!transform->enabled)
			{
				continue;
			}
			
			if (transform->GetParent() == nullptr)
			{
				continue;
			}

			if (!transform->GetParent()->worldBuilt)
			{
				complete = false;
				continue;
			}
			else
			{
				if (transform->GetParent()->isDirty)
				{
					//Rebuild world matrix because parent was dirty
					transform->isDirty = true;
					transform->worldBuilt = false;
				}
				else
				{
					if (!transform->worldBuilt || transform->isDirty)
					{
						transform->GetParent()->isDirty = true;
						complete = false;
					}
				}
			}

			if (transform->worldBuilt)
			{
				continue;
			}

			transform->isDirty = true;
			glm::mat4 parentMatrix = transform->GetParent()->worldMatrix.GetMat();
			glm::vec3 sca, pos, skew;
			glm::quat rot;
			glm::vec4 pers;
			glm::decompose(parentMatrix, sca, rot, pos, skew, pers);
			rot = glm::inverse(rot);
			parentMatrix = glm::translate(glm::mat4(), pos) * glm::toMat4(rot);

			glm::mat4 localMatrix = transform->localMatrix.GetMat();
			transform->worldMatrix.SetMat(parentMatrix * localMatrix);

			transform->worldBuilt = true;
		}
	}

	//Set remaining to not dirty
	for (auto entity : transforms)
	{
		Transform* transform = entity.component<Transform>();
		if (!transform->enabled)
		{
			continue;
		}

		transform->isDirty = false;
	}
}
