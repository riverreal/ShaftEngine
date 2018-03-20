#include "Renderer.h"
#include "../../Core.h"
#include "../../System/Misc/EngineConfig.h"
#include <imgui/imgui.h>

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
	std::cout << "Renderer destructor" << std::endl;
	Destroy();
}

void Renderer::Initialize()
{
	auto bgfxRenderRype = ConvertRendererTypeToBGFX(m_config.rendererType);
	m_debugFlags = BGFX_DEBUG_TEXT | BGFX_DEBUG_STATS;
	m_resetFlags = BGFX_RESET_VSYNC;
	if (!bgfx::init(bgfxRenderRype, 0))
	{
		std::cout << "Could not initialize bgfx" << std::endl;
		throw std::runtime_error("bgfx init failed");
		return;
	}
	bgfx::reset(m_config.width, m_config.height, m_resetFlags);
	bgfx::setDebug(m_debugFlags);

	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f, 0);
	
	//imguiCreate();
}

void Renderer::Draw()
{
	//imguiEndFrame();
	bgfx::setViewRect(0, 0, 0, m_width, m_height);

	bgfx::touch(0);
	/*
	bgfx::dbgTextClear();
	bgfx::dbgTextPrintf(0, 1, 0x0f, "Test text using bgfx");

	const bgfx::Stats* stats = bgfx::getStats();
	bgfx::dbgTextPrintf(0, 2, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters."
		, stats->width
		, stats->height
		, stats->textWidth
		, stats->textHeight
	);
	*/
	bgfx::frame();
}

void Renderer::Destroy()
{
	//imguiDestroy();
	bgfx::shutdown();
}
