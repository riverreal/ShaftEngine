#pragma once

#include <Shaft/Core.h>
#include "../../Engine/System/Misc/EngineConfig.h"
#include "../Engine/Engine.h"
#include "../Engine/System/ResourceManager.h"
#include "../Engine/System/MeshManager.h"
#include "../Engine/Graphics/MaterialManager.h"
#include "../Engine/System/FileSystem.h"
#include "../Engine/System/Input/Input.h"
#include "../Engine/World.h"

namespace Shaft {
	class Engine;

	class Application
	{
	public:
		Application();
		~Application();
		void Initialize();
		void Run();

	protected:
		virtual void OnInitialize() = 0;
		virtual void Frame() = 0;

	protected:
		eastl::unique_ptr<Engine> m_engine;
		World* m_world;
		MaterialManager* m_materialManager;
		TextureManager* m_textureManager;
		MeshManager* m_meshManager;
		FileSystem* m_fileSystem;
		EngineConfig m_engineConfig;
	};
}