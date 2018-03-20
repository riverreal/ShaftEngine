#pragma once

#include "../../Core.h"

namespace Shaft {
	struct RendererConfig;

	class Renderer
	{
	public:
		Renderer(const RendererConfig& renderConfig);
		~Renderer();
		virtual void Initialize();
		virtual void Draw();
		virtual void Destroy();

	private:
		const RendererConfig& m_config;
		uint32 m_width;
		uint32 m_height;
		uint32 m_debugFlags;
		uint32 m_resetFlags;
	};
}