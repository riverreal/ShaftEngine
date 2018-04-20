#pragma once

#include <Shaft/Core.h>

namespace Shaft {
	class World;
	class ResourceManager;
	struct RendererConfig;

	class Renderer
	{
	public:
		Renderer(const RendererConfig& renderConfig);
		~Renderer();
		void Initialize(World* world, ResourceManager* resourceManager);
		void Draw();
		void Destroy();

	private:
		World * m_world;
		ResourceManager* m_resourceManager;
		const RendererConfig& m_config;
		uint32 m_width;
		uint32 m_height;
		uint32 m_debugFlags;
		uint32 m_resetFlags;
		bgfx::ProgramHandle testProgram;
		bgfx::UniformHandle m_color;
	};
}