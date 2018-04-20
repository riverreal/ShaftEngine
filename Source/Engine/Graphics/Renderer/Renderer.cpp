#include "Renderer.h"
#include "../../System/Misc/EngineConfig.h"
#include "../Engine/World.h"
#include "../Engine/System/ResourceManager.h"
#include "../Engine/System/MeshManager.h"
#include <bx/math.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/matrix.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <brtshaderc/brtshaderc.h>

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

void Renderer::Initialize(World* world, ResourceManager* resourceManager)
{
	m_world = world;
	m_resourceManager = resourceManager;
	auto bgfxRenderRype = ConvertRendererTypeToBGFX(m_config.rendererType);
	m_debugFlags = BGFX_DEBUG_TEXT;
	uint32 vsyncFlag = m_config.fpsConfig.vsync ? BGFX_RESET_VSYNC : 0;
	m_resetFlags = vsyncFlag;
	if (!bgfx::init(bgfxRenderRype, 0))
	{
		throw std::runtime_error("bgfx init failed");
		return;
	}
	bgfx::reset(m_config.width, m_config.height, m_resetFlags);
	bgfx::setDebug(m_debugFlags);

	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x000000ff, 1.0f, 0);

	const bgfx::Memory* memVsh = shaderc::compileShader(shaderc::ST_VERTEX, "../../../Source/Engine/Graphics/Shaders/UberVS.sc", "../../../Dependencies/bgfx/src");
	bgfx::ShaderHandle vsh = bgfx::createShader(memVsh);
	const bgfx::Memory* memFsh = shaderc::compileShader(shaderc::ST_FRAGMENT, "../../../Source/Engine/Graphics/Shaders/UberFS.sc", "../../../Dependencies/bgfx/src");
	bgfx::ShaderHandle fsh = bgfx::createShader(memFsh);
	testProgram = bgfx::createProgram(vsh, fsh, true);
	m_color = bgfx::createUniform("u_color", bgfx::UniformType::Vec4);
}

void Renderer::Draw()
{
	float at[3] = { 0.0f, 0.0f, 0.0f };
	float eye[3] = { 0.0f, 0.0f, -10.0f };
 	float view[16];
	bx::mtxLookAt(view, eye, at);

	float proj[16];
	bx::mtxProj(proj, 60.0f, float(m_width) / float(m_height), 0.1f, 1000.0f, bgfx::getCaps()->homogeneousDepth);

	bgfx::setViewTransform(0, view, proj);
	bgfx::setViewRect(0, 0, 0, m_width, m_height);

	bgfx::touch(0);
	
	for (auto& idActor : m_world->GetActors())
	{
		auto actor = idActor.actor.get();
		auto meshComp = actor->GetEntity().component<MeshComponent>();
		auto transform = actor->GetEntity().component<Transform>();
		if (meshComp != nullptr && transform != nullptr)
		{
			glm::mat4 mat4 = transform->worldMatrix.GetMat();
			float* mat = glm::value_ptr(mat4);
			bgfx::setTransform(mat);
			float color[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
			bgfx::setUniform(m_color, &color);
			auto meshType = m_resourceManager->GetMeshManager().GetMeshTypes()[meshComp->meshId];
			if (!meshType.created)
			{
				continue;
			}
			
			bgfx::setVertexBuffer(0, meshType.vb);
			bgfx::setIndexBuffer(meshType.ib);

			bgfx::setState(0
				| BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A
				| BGFX_STATE_WRITE_Z | BGFX_STATE_DEPTH_TEST_LESS
				| BGFX_STATE_CULL_CW | BGFX_STATE_MSAA
				| BGFX_STATE_PT_TRISTRIP
			);

			bgfx::submit(0, testProgram);
		}
	}

	bgfx::frame();
}

void Renderer::Destroy()
{
	bgfx::destroy(testProgram);
	bgfx::destroy(m_color);
	bgfx::shutdown();
}
