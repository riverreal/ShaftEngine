#include "BillboardSystem.h"

#include "../../../World.h"
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Shaft;

BillboardSystem::BillboardSystem(EngineEntityManager* entityManager, World* world)
    : m_entityManager(entityManager),
    m_world(world)
{
}

BillboardSystem::~BillboardSystem()
{   
}

void BillboardSystem::Update()
{
    auto camera = m_world->GetMainCamera();    
    if(!camera)
    {
        return;
    }
    
    for (auto entity : m_entityManager->entities_with_components<Transform, BillboardComponent>())
    {
        auto transform = entity.component<Transform>();
		auto camComp = camera->GetEntity().component<CameraComponent>();
		auto posRow = transform->worldMatrix.values[3];
		auto billboardMat = camComp->viewMatrix;
		billboardMat.values[3] = posRow;
		transform->isDirty = false;
		transform->worldBuilt = true;
		auto scale = transform->GetScale();
		billboardMat.SetMat(glm::scale(billboardMat.GetMat(), glm::vec3(scale.x, scale.y, scale.z)));
		transform->worldMatrix = billboardMat;
    }
}