#include "Renderer.h"
#include "../../Core.h"
#include "../../System/Misc/EngineConfig.h"

using namespace Shaft;

Renderer::Renderer(const RendererConfig & renderConfig)
	:m_config(renderConfig),
	m_width(renderConfig.width),
	m_height(renderConfig.height),
	m_debugFlags(0),
	m_resetFlags(0)
{
}

Renderer::~Renderer()
{
	Destroy();
}

void Renderer::Initialize()
{
	auto bgfxRenderRype = ConvertRendererTypeToBGFX(m_config.rendererType);
	m_debugFlags = BGFX_DEBUG_TEXT;
	m_resetFlags = BGFX_RESET_VSYNC;
	if (!bgfx::init(bgfxRenderRype, 0))
	{
		throw std::runtime_error("bgfx init failed");
		return;
	}
	bgfx::reset(m_config.width, m_config.height, m_resetFlags);
	bgfx::setDebug(m_debugFlags);

	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x000000ff, 1.0f, 0);
}

void Renderer::Draw()
{
	bgfx::setViewRect(0, 0, 0, m_width, m_height);

	bgfx::touch(0);

	bgfx::frame();
}

void Renderer::Destroy()
{
	bgfx::shutdown();
}
