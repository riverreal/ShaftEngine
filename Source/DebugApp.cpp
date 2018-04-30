#include <Shaft/DebugApp.h>
#include "Engine/EngineFactory.h"
#include "Engine/Engine.h"
#include "Engine/System/Window/WindowHandle.h"
#include "Engine/Graphics/Renderer/Renderer.h"
#include "Engine/System/ResourceManager.h"
#include "Engine/System/MeshManager.h"
#include "Engine/Graphics/ShapeBuilder.h"
#include "Engine/Graphics/ModelBuilder.h"
#include "Engine/World.h"
#include <thread>

using namespace Shaft;

DebugApp::DebugApp()
{
}

DebugApp::~DebugApp()
{
}

void DebugApp::Initialize()
{
	m_engineConfig.buildTarget = Windows;
	m_engineConfig.renderConfig.rendererType = Direct3D11;
	m_engineConfig.windowConfig.isResizeable = false;
	m_engineConfig.appInfo.appName = "Shaft Engine Test";
	m_engineConfig.appInfo.appVersion = Version(0, 0, 1);
	m_engineConfig.renderConfig.appInfo = m_engineConfig.windowConfig.appInfo = m_engineConfig.appInfo;
	m_engineConfig.renderConfig.isValidationEnabled = true;
	m_engineConfig.renderConfig.engineName = "Shaft Engine";
	m_engineConfig.engineVersion = m_engineConfig.renderConfig.engineVersion = Version(0, 0, 1);
	m_engineConfig.renderConfig.fpsConfig.vsync = true;
	m_engineConfig.renderConfig.fpsConfig.fps = 60;

	EngineFactory engineFactory;

	m_engine = engineFactory.CreateEngine(m_engineConfig);
	m_engine->Initialize();

	m_cube = m_engine->GetWorld().CreateActor();
	auto meshID = m_engine->GetResourceManager().GetMeshManager().CreateMeshType(ShapeBuilder::CreateCube(1, 1, 1), "Cube");
	m_cube->AddComponent<MeshComponent>(meshID);

	auto sphere = m_engine->GetWorld().CreateActor();
	meshID = m_engine->GetResourceManager().GetMeshManager().CreateMeshType(ShapeBuilder::CreateSphere (0.5f, 10, 10), "Sphere");
	sphere->AddComponent<MeshComponent>(meshID);
	sphere->GetTransform()->SetPosition(Vec3f(2, 0, 0));
	m_cube->AddChild(sphere);

	auto sphere2 = m_engine->GetWorld().CreateActor();
	sphere2->AddComponent<MeshComponent>(meshID);
	sphere2->GetTransform()->SetPosition(Vec3f(1, 0, 0));
	sphere->AddChild(sphere2);


	auto model = m_engine->GetWorld().CreateActor();
	meshID = m_engine->GetResourceManager().GetMeshManager().CreateMeshType(ModelBuilder::CreateModel("../Resource/Models/Sword.fbx"), "Model");
	model->AddComponent<MeshComponent>(meshID);
	model->GetTransform()->SetPosition(Vec3f(-1, 0, 0));
	Animate();
	
	//AppInit();
}

void Shaft::DebugApp::Run()
{
	FPSConfig& fpsConfig = m_engineConfig.renderConfig.fpsConfig;
	m_engine->GetTimer().TimeStart();
	while (!m_engine->GetWindow().CloseWindow())
	{
		m_engine->GetTimer().Tick();
		float dt = m_engine->GetTimer().GetDeltaTime();

		if (!fpsConfig.vsync && fpsConfig.capFPS)
		{
			auto sleepMS = static_cast<int32>(1000.0f / (float)fpsConfig.fps - dt * 1000.0f);
			if (sleepMS > 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(sleepMS));
			}
		}

		m_engine->GetWindow().PollEvents();
		
		m_engine->GetWorld().Update(dt);

		//AppRun();
		glm::quat quat = m_engine->GetWorld().GetActors()[0].actor->GetTransform()->GetRotation().GetQuat();
		Quaternion q;
		q.SetQuat(glm::rotate(quat, 1.0f * dt, glm::vec3(0, 1, 0)));
		m_engine->GetWorld().GetActors()[0].actor->GetTransform()->SetRotation(q);

		quat = m_engine->GetWorld().GetActors()[1].actor->GetTransform()->GetRotation().GetQuat();
		q.SetQuat(glm::rotate(quat, 1.0f * dt, glm::vec3(0, 1, 0)));
		m_engine->GetWorld().GetActors()[1].actor->GetTransform()->SetRotation(q);

		m_tween.Update(dt);

#if SHAFT_EDITOR_ENABLED
		m_engine->GetEditor().Draw();
#endif

		m_engine->GetRenderer().Draw();
	}
}

void Shaft::DebugApp::Animate()
{
	float posY = m_cube->GetTransform()->GetPosition().y;
	STween::STween<float> yMoveTween = m_tween.From(posY).To(4.0f).Time(2.0f).OnStep([this](float y) {
		auto pos = m_cube->GetTransform()->GetPosition();
		pos.y = y;
		m_cube->GetTransform()->SetPosition(pos);
	}).Easing(STween::BackInOut);
	yMoveTween.Reversed(true).OnFinish([this]() {this->Animate(); });
	m_tween.Chain(&yMoveTween);
}
