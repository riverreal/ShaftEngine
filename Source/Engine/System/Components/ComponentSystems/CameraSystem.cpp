#include "CameraSystem.h"

#include <bx/math.h>
#include <glm/matrix.hpp>

using namespace Shaft;

CameraSystem::CameraSystem(EngineEntityManager* manager)
    : m_entityManager(manager)
{
}

CameraSystem::~CameraSystem()
{
}

void CameraSystem::Initialize(float w, float h)
{
    m_width = w;
    m_height = h;
}

void CameraSystem::Update()
{
    for (auto entity : m_entityManager->entities_with_components<Transform, CameraComponent>())
    {
        Transform* transform = entity.component<Transform>();
        CameraComponent* camera = entity.component<CameraComponent>();

        //if(camera->dirty)
        {
            camera->SetAspectRatio(m_width / m_height);

            bx::mtxProj((float*)(&camera->projMatrix), camera->GetFOV(), camera->GetAspectRatio(), camera->GetNear(), camera->GetFar(), bgfx::getCaps()->homogeneousDepth);
            camera->dirty = false;
        }

        auto mat = transform->worldMatrix.GetMat();
        camera->viewMatrix.SetMat(glm::inverse(mat));
    }
}