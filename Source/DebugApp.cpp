#include "DebugApp.h"
#include "Engine/EngineFactory.h"
#include "Engine/Engine.h"
#include "Engine/System/Window/WindowHandle.h"
#include "Engine/Graphics/Renderer/Renderer.h"
#include "Engine/System/ResourceManager.h"
#include "Engine/System/MeshManager.h"
#include "Engine/Graphics/MaterialManager.h"
#include "Engine/Graphics/TextureManager.h"
#include "Engine/System/FileSystem.h"
#include "Engine/World.h"
#include <thread>
#include <async++.h>
#include <EASTL/vector.h>

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
	auto meshID = m_engine->GetResourceManager().GetMeshManager().LoadShape(ShapeType::Cube);
	m_cube->AddComponent<BillboardComponent>();
	m_cube->AddComponent<MeshComponent>(meshID);

	auto sphere = m_engine->GetWorld().CreateActor();
	meshID = m_engine->GetResourceManager().GetMeshManager().LoadShape(ShapeType::Sphere);
	sphere->AddComponent<MeshComponent>(meshID);
	sphere->GetTransform()->SetPosition(Vec3f(2, 0, 0));
	m_cube->AddChild(sphere);

	auto sphere2 = m_engine->GetWorld().CreateActor();
	sphere2->AddComponent<MeshComponent>(meshID);
	sphere2->GetTransform()->SetPosition(Vec3f(1, 0, 0));
	sphere->AddChild(sphere2);

	auto resourcePath = m_engine->GetResourceManager().GetFileSystem().GetResourcePath();
	 auto model = m_engine->GetWorld().CreateActor();
	 meshID = m_engine->GetResourceManager().GetMeshManager().LoadMesh("ship.glb", 1);
	 auto meshComp = model->AddComponent<MeshComponent>(meshID);
	 meshComp->matInstanceId = m_engine->GetResourceManager().GetMaterialManager().LoadMaterialInstance("ship.min", 1);
	 model->GetTransform()->SetPosition(Vec3f(-5, 0, 0));
	 model->GetTransform()->SetScale(Vec3f(1.0f));
	 model->SetActive(false);
	//Animate();

	auto cam = m_engine->GetWorld().CreateActor();
	auto camComp = cam->AddComponent<CameraComponent>();
	cam->GetTransform()->SetPosition(Vec3f(2.0f, 0, -10.0f));
	m_engine->GetWorld().SetMainCamera(cam);
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

		auto pos = m_engine->GetWorld().GetMainCamera()->GetTransform()->GetPosition();
		auto rot = m_engine->GetWorld().GetMainCamera()->GetTransform()->GetRotation();

		if(m_engine->GetInput().GetKeyState().keys[KeyState::Key::D])
		{	
			pos.x += 2.0f * dt;
		}
		if(m_engine->GetInput().GetKeyState().keys[KeyState::Key::A])
		{	
			pos.x -= 2.0f * dt;
		}
		if (m_engine->GetInput().GetKeyState().keys[KeyState::Key::W])
		{
			pos.z += 2.0f * dt;
		}
		if (m_engine->GetInput().GetKeyState().keys[KeyState::Key::S])
		{
			pos.z -= 2.0f * dt;
		}
		if (m_engine->GetInput().GetKeyState().keys[KeyState::Key::Q])
		{
			auto q = rot.GetQuat();
			rot.SetQuat(glm::rotate(q, 1.0f * dt, glm::vec3(0, 1, 0)));
		}
		if (m_engine->GetInput().GetKeyState().keys[KeyState::Key::E])
		{
			auto q = rot.GetQuat();
			rot.SetQuat(glm::rotate(q, -1.0f * dt, glm::vec3(0, 1, 0)));
		}

		m_engine->GetWorld().GetMainCamera()->GetTransform()->SetRotation(rot);
		m_engine->GetWorld().GetMainCamera()->GetTransform()->SetPosition(pos);

		//AppRun();
		glm::quat quat = m_engine->GetWorld().GetActors()[0].actor->GetTransform()->GetRotation().GetQuat();
		
		Quaternion q;
		q.SetQuat(glm::rotate(quat, 1.0f * dt, glm::vec3(0, 1, 0)));
		m_cube->GetTransform()->SetRotation(q);

		q.SetQuat(glm::rotate(quat, 1.0f * dt, glm::vec3(0, 1, 0)));
		//m_engine->GetWorld().GetActors()[1].actor->GetTransform()->SetRotation(q);

		q.SetQuat(glm::rotate(quat, 1.0f * dt, glm::vec3(0, 1, 0)));
		//m_engine->GetWorld().GetActors()[3].actor->GetTransform()->SetRotation(q);

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
